#ifndef __SESSION_H__
#define __SESSION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QMessageBox>
#include <QtNetwork>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include "global.h"
#include "MyQLineEdit.h"
#include "MyQPushButton.h"

#define DEFAULT_SESSION_PORT 7945

class MyQSession: public QObject
{
    Q_OBJECT

public:
        MyQSession(void)
        {
            odbc = new ODBC_GlobalDriverStruct;
            client = new QTcpSocket(this);

            timer = new QTimer();
            timeout = 5000;
            timer->setInterval(5000);

            host = "127.0.0.0";
            port = 7945;

            connect(client, SIGNAL(connected()), this, SLOT(startTransfer()));
        }

	QString user;
        QString pass;
	QString host;
	int	port;

        int  timeout;
        bool timeout_notify;

        struct ODBC_GlobalDriverStruct *odbc;

        friend QDataStream &operator << (QDataStream &out, QString str)
        {
            out << str;
            return out;
        }

        friend QDataStream &operator >> (QDataStream &in, QString str)
        {
            in >> str;
            return in;
        }

        void start(void)
        {
            if (timeout < 1)
            {
                printf("warning: session interval to low (< 1 mmsec.)\n");
                //return;
            }

            connect(timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

            timer->setInterval(timeout);
            timer->start();

            QHostAddress addr(host);
            connect(client, SIGNAL(error (QAbstractSocket::SocketError)),
                    this,   SLOT(TCPerror(QAbstractSocket::SocketError)));
            client->connectToHost(addr, port);
            if (!client->waitForConnected(timeout))
            {
                timer->setInterval(timeout);
                disconnect(timer);
            }
        }

        void stop(void)
        {
            timer->stop();
        }

public slots:
        void TCPerror(QAbstractSocket::SocketError _error)
        {
            QMessageBox* msgBox = new QMessageBox();
            msgBox->setWindowTitle("Session Error");
            msgBox->setText(client->errorString());
            msgBox->exec();

            client->close();
            timer->setInterval(timeout);
            timer->stop();
            disconnect(timer);
        }

        void startTransfer()
        {
            odbc->version = 1;
            odbc->user_name = user;
            odbc->pass_name = pass;

            QDataStream stream(client);
            stream << odbc->version
                   << odbc->protocoll_type
                   << odbc->protocoll_command
                   << odbc->database
                   << odbc->sql_cmd
                   << odbc->user_name
                   << odbc->pass_name
                   << odbc->session
                   << odbc->error_num
                   << odbc->body_length;
        }

        void OnTimer()
        {
            if (!timer->isActive()) return;
            if (timer->interval() == timeout)
            {
                timer->stop();

                if (timeout_notify == true)
                {
                    QMessageBox* msgBox = new QMessageBox();
                    msgBox->setWindowTitle("Session Timeout");
                    msgBox->setText("Sorry, Session Timeout\nConnection failed.");
                    msgBox->exec();
                }
                client->close();
            }
        }
public:
        QTimer *timer;
        QTcpSocket *client;
};


class MyQDataBase: public QObject
{
    Q_OBJECT
public:
    MyQDataBase(void)
    {
        active = false;
    }

    MyQSession *session;
    QString databaseName;
    bool active;

    void open(void)
    {
        if (session)
        {
            if (!session->timer->isActive())
            {
                QMessageBox* msgBox = new QMessageBox();
                msgBox->setWindowTitle("Database Error");
                msgBox->setText("Sorry, Database not connected,\nConnection failed.");
                msgBox->exec();

                active = false;
                return;
            }
        }
    }
};

class MyQQuery: public QObject
{
    Q_OBJECT
public:
    MyQQuery(void) { }
    MyQQuery(QObject *_parent=0) { parent = _parent; }
    QObject *parent;
};

class MyQDataField: public QObject
{
    Q_OBJECT
public:
    MyQDataField(QObject *_parent) { parent = _parent; }
    QObject *parent;

    QString field;
    QString value;

    void bind(class MyQLineEdit   *w);
    void bind(class MyQPushButton *w);
};

#endif
