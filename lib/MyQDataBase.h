#ifndef MYQDATABASE_H__
#define MYQDATABASE_H__

#include "pch.h"

class MyQDataBase: public QObject
{
    Q_OBJECT
public:
    MyQDataBase(void)
    {
        active = false;
        session = NULL;
    }

    MyQDataBase(QWidget *parent = 0) { }

    class MyQSession *session;
    QString databaseName;
    bool active;

    void open(void);
/*    {

        if (session != NULL)
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
*/
};

#endif
