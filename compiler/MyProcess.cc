#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include "MyCompiler.h"
#include "MyProcess.h"

extern dBase::MainWindow *win;

MyProcess::MyProcess(QObject *parent, QString prg, QStringList args) : QObject(parent)
{
    slData.append("Start....");
    win->getAusgabe()->setModel(new QStringListModel(slData));

    try {
    mproc = new QProcess(parent);
    mproc->start(prg,args);
    } catch (...) { }

    connect(mproc,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(mproc,SIGNAL(readyReadStandardError()) ,this,SLOT(readyReadStandardError()));
    connect(mproc,SIGNAL(error(QProcess::ProcessError)),this,SLOT(onError(QProcess::ProcessError err)));
    connect(mproc,SIGNAL(finished(int ec, QProcess::ExitStatus est)), this, SLOT(finished(int ec, QProcess::ExitStatus est)));
}


void MyProcess::onError(QProcess::ProcessError err)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("error");
    msgBox->setText(QString("Error: %1").arg(err));
    msgBox->exec();
}

void MyProcess::readyReadStandardOutput()
{
    QString bd = mproc->readAll().data();
    slData.append(bd.remove(QChar('\n')));
    win->getAusgabe()->setModel(new QStringListModel(slData));
}

void MyProcess::readyReadStandardError()
{
    QString bd = mproc->readAll().data();
    slData.append(bd.remove(QChar('\n')));
    win->getAusgabe()->setModel(new QStringListModel(slData));
}

void MyProcess::finished(int ec, QProcess::ExitStatus est)
{
    QString es;
    if (ec > 0) es = "Exit mit Fehler.";
    else        es = "Exit normal";

    slData.append(es.remove(QChar('\n')));
    win->getAusgabe()->setModel(new QStringListModel(slData));

    delete mproc;
}
