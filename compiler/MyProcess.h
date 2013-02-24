#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QObject>
#include <QProcess>


class MyProcess: public QObject
{
    Q_OBJECT
public:
    MyProcess(QObject *parent, QString prg, QStringList args);

    QStringList slData;
    QProcess *mproc;

public slots:
    void readyReadStandardOutput();
    void readyReadStandardError();
    void onError(QProcess::ProcessError err);
    void finished(int ec, QProcess::ExitStatus est);
};


#endif // MYPROCESS_H
