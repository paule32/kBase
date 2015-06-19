#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QMdiSubWindow>
#include <QFileDialog>

#include "childwindow.h"

extern void msgbox(QString,QString);
extern void prepare_compile_file(const char*);

extern int line_num;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSettings settings("dbase.ini", QSettings::IniFormat);
 
    ui->setupUi(this);

    designerWindow = new ChildWindow(ui->mdiArea);
    designerWindow->setAttribute(Qt::WA_DeleteOnClose);
    designerWindow->show();
    ui->mdiArea->subWindowList().at(_DesignerWindow)->resize(
                settings.value("Designer/W",200).toInt(),
                settings.value("Designer/H",200).toInt());
    ui->mdiArea->subWindowList().at(_DesignerWindow)->move(
                settings.value("Designer/X",120).toInt(),
                settings.value("Designer/Y",20).toInt());

    editorWindow = new ChildWindowEditor(ui->mdiArea);
    editorWindow->setAttribute(Qt::WA_DeleteOnClose);
    editorWindow->show();
    ui->mdiArea->subWindowList().at(_EditorWindow)->resize(
                settings.value("Editor/W",200).toInt(),
                settings.value("Editor/H",200).toInt());
    ui->mdiArea->subWindowList().at(_EditorWindow)->move(
                settings.value("Editor/X",120).toInt(),
                settings.value("Editor/Y",20).toInt());

    propertyWindow = new ChildWindowProperty(ui->mdiArea);
    propertyWindow->setAttribute(Qt::WA_DeleteOnClose);
    propertyWindow->show();
    ui->mdiArea->subWindowList().at(_PropertyWindow)->resize(
                settings.value("Properties/W",200).toInt(),
                settings.value("Properties/H",200).toInt());
    ui->mdiArea->subWindowList().at(_PropertyWindow)->move(
                settings.value("Properties/X",120).toInt(),
                settings.value("Properties/Y",20).toInt());

    componentsWindow = new ChildWindowComponents(ui->mdiArea);
    componentsWindow->setAttribute(Qt::WA_DeleteOnClose);
    componentsWindow->show();
    ui->mdiArea->subWindowList().at(_ComponentWindow)->resize(
                settings.value("Components/W",200).toInt(),
                settings.value("Components/H",200).toInt());
    ui->mdiArea->subWindowList().at(_ComponentWindow)->move(
                settings.value("Components/X",120).toInt(),
                settings.value("Components/Y",20).toInt());

    // connect menu items ...
    connect(ui->actionBeenden, SIGNAL(triggered()), this, SLOT(WindowSlotClose()));

    connect(ui->actionDatei_oder_Projekt_ffnen, SIGNAL(triggered()), this, SLOT(EditOpenFile()));
    connect(ui->actionSpeichern, SIGNAL(triggered()), this, SLOT(EditSaveFile()));
    connect(ui->actionSpeichern_unter, SIGNAL(triggered()), this, SLOT(EditSaveFileAs()));

    connect(ui->actionProjektAusfuehren, SIGNAL(triggered()), this, SLOT(EditRunCode()));
}

void MainWindow::WindowSlotClose() { exit(0); }

void MainWindow::EditRunCode()
{
    ChildWindowEditor *editor;
    editor = dynamic_cast<ChildWindowEditor*>(ui->mdiArea->subWindowList().at(_EditorWindow));

    if (editor->editWidget->editWidget->document()->toPlainText().toStdString().length() < 1) {
        return;
    }
    if (editor->editWidget->editWidget->EditorFileName.length() < 0) {
        EditSaveFileAs();
    }

    if (editor->editWidget->editWidget->document()->isModified() == true) {
        EditSaveFile();
        editor->editWidget->editWidget->document()->setModified(false);
    }

    QString src = editor->editWidget->editWidget->EditorFileName;
    int lines = editor->editWidget->editWidget->lines;
    prepare_compile_file(src.toStdString().c_str());
    msgbox(QString("Information"),QString("Zeilen: %1\nKonvertierung abgeschlossen.").
    arg(lines));
}

void MainWindow::EditSaveFile()
{
    ChildWindowEditor *editor;
    editor = dynamic_cast<ChildWindowEditor*>(ui->mdiArea->subWindowList().at(_EditorWindow));

    if (editor->editWidget->editWidget->EditorFileName.length() < 1) {
        EditSaveFileAs();
        return;
    }

    QString src = editor->editWidget->editWidget->toPlainText();
    QFile file(editor->editWidget->editWidget->EditorFileName);
    if (!file.open(QIODevice::WriteOnly))
    return;

    QTextStream out(&file);
    out << src;
    file.close();
}

void MainWindow::EditOpenFile()
{
    /*)
    static bool f = false;
    if (!f) ui->mdiArea->subWindowList().at(_ComponentWindow)->show();
    else    ui->mdiArea->subWindowList().at(_ComponentWindow)->hide();

    f = !f;
    */

    QString fileName = QFileDialog::getOpenFileName(this,
       tr("Datei öffnen"),
       "./examples",
       tr("Dateien (*.prg *.wfm)")
    );

    if (fileName.length() > 0)
    {
        QString src;
        QFile   file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            src.append(line);
        }

        ChildWindowEditor *editor;
        editor = dynamic_cast<ChildWindowEditor*>(ui->mdiArea->subWindowList().at(_EditorWindow));
        editor->editWidget->editWidget->setPlainText(src);
        editor->editWidget->editWidget->EditorFileName = fileName;
    } else {
        msgbox(QString("Information"),
               QString("Editor Datei konnte nicht geöffnet werden !!!"));
    }
}

void MainWindow::EditSaveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
       tr("Datei speichern"),
       "./examples",
       tr("Dateien (*.prg *.wfm)")
    );

    if (fileName.length() > 0)
    {
        ChildWindowEditor *editor;
        editor = dynamic_cast<ChildWindowEditor*>(ui->mdiArea->subWindowList().at(_EditorWindow));

        QString src = editor->editWidget->editWidget->toPlainText();
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        return;

        QTextStream out(&file);
        out << src;
        file.close();

        editor->editWidget->editWidget->EditorFileName = fileName;
    } else {
        msgbox(QString("Warnung"),
               QString("Datei: \"%1\" konnte nicht gespeichsert werdne !!!")
               .arg(fileName));
    }
}

MainWindow::~MainWindow()
{
    delete componentsWindow;
    delete propertyWindow;
    delete editorWindow;
    delete designerWindow;

    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *evt)
{
    saveSettings();
}

void MainWindow::resizeEvent(QResizeEvent *evt)
{
    ui->mdiArea->resize(width(),height()-25);
}

void MainWindow::saveSettings()
{
    QSettings settings("dbase.ini", QSettings::IniFormat);

    settings.setValue("Designer/X",ui->mdiArea->subWindowList().at(_DesignerWindow)->pos().x());
    settings.setValue("Designer/Y",ui->mdiArea->subWindowList().at(_DesignerWindow)->pos().y());
    settings.setValue("Designer/W",ui->mdiArea->subWindowList().at(_DesignerWindow)->width());
    settings.setValue("Designer/H",ui->mdiArea->subWindowList().at(_DesignerWindow)->height());

    settings.setValue("Editor/X",ui->mdiArea->subWindowList().at(_EditorWindow)->pos().x());
    settings.setValue("Editor/Y",ui->mdiArea->subWindowList().at(_EditorWindow)->pos().y());
    settings.setValue("Editor/W",ui->mdiArea->subWindowList().at(_EditorWindow)->width());
    settings.setValue("Editor/H",ui->mdiArea->subWindowList().at(_EditorWindow)->height());

    settings.setValue("Properties/X",ui->mdiArea->subWindowList().at(_PropertyWindow)->pos().x());
    settings.setValue("Properties/Y",ui->mdiArea->subWindowList().at(_PropertyWindow)->pos().y());
    settings.setValue("Properties/W",ui->mdiArea->subWindowList().at(_PropertyWindow)->width());
    settings.setValue("Properties/H",ui->mdiArea->subWindowList().at(_PropertyWindow)->height());

    settings.setValue("Components/X",ui->mdiArea->subWindowList().at(_ComponentWindow)->pos().x());
    settings.setValue("Components/Y",ui->mdiArea->subWindowList().at(_ComponentWindow)->pos().y());
    settings.setValue("Components/W",ui->mdiArea->subWindowList().at(_ComponentWindow)->width());
    settings.setValue("Components/H",ui->mdiArea->subWindowList().at(_ComponentWindow)->height());
}
