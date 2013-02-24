#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include "server.h"

ServerWindow::ServerWindow(void)
{
    resize(300,250);

    start_btn = new QPushButton("Starten",this);
    start_btn->show();

    server = new QTcpServer;
    client = new QTcpSocket;

    odbc = new ODBC_GlobalDriverStruct;

    connect(start_btn, SIGNAL(clicked()),       this, SLOT(start_btnOnClick()));
    connect(server,    SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

void ServerWindow::startRead()
{
    QDataStream stream(client);
    stream >> odbc->version
           >> odbc->protocoll_type
           >> odbc->protocoll_command
           >> odbc->database
           >> odbc->sql_cmd
           >> odbc->user_name
           >> odbc->pass_name
           >> odbc->session
           >> odbc->error_num
           >> odbc->body_length;

    if (odbc->version == 1)
    {
        QSqlDatabase db(QSqlDatabase::addDatabase("QODBC"));
        db.setDatabaseName("Beispiel");
        bool ok = db.open();

        if (ok == false)
        {
            QMessageBox* msgBox = new QMessageBox();
            msgBox->setWindowTitle("Error");
            msgBox->setText(db.lastError().text());
            msgBox->exec();

            return;
        }

        db.close();
    }
}

ServerWindow::~ServerWindow()
{
    server->close();
}

int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    app.addLibraryPath(app.applicationDirPath());

    ServerWindow *win = new ServerWindow();
    win->show();

    return app.exec();
}
