#ifndef __SERVER_H__
#define __SERVER_H__

#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>
#include "global.h"

class ServerWindow: public QWidget
{
    Q_OBJECT
public:
    ServerWindow(void);
    ~ServerWindow();

    friend QDataStream &operator << (QDataStream &out, QString str)
    {
        out << str;
        return out;
    }

    friend QDataStream &operator >> (QDataStream &in, QString str) { in >> str; return in; }
    friend QDataStream &operator >> (QDataStream &in, double  str) { in >> str; return in; }
    friend QDataStream &operator >> (QDataStream &in, bool    str) { in >> str; return in; }
    friend QDataStream &operator >> (QDataStream &in, int     str) { in >> str; return in; }

public slots:
    void start_btnOnClick()
    {
        if (start_btn->text() == "Starten")
        {
            start_btn->setText("Stopp");
            server->listen(QHostAddress::Any, 7945);
        }
        else {
            start_btn->setText("Starten");
            server->close();
        }
    }

    void acceptConnection()
    {
        client = server->nextPendingConnection();
        connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
    }

    void startRead();

private:
    struct ODBC_GlobalDriverStruct *odbc;

    QPushButton *start_btn;
    QTcpServer *server;
    QTcpSocket *client;
};

#endif
