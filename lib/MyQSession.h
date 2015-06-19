#ifndef __MYQSESSION_H__
#define __MYQSESSION_H__

#include "pch.h"

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

#endif

