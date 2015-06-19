#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>

#include "childwindow.h"
#include "childwindoweditor.h"
#include "childwindowproperty.h"
#include "childwindowcomponents.h"

enum WindowType { _DesignerWindow = 0,
                  _EditorWindow = 1,
                  _PropertyWindow = 2,
                  _ComponentWindow = 3
                };

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void WindowSlotClose();
    void EditRunCode();
    void EditOpenFile();
    void EditSaveFile();
    void EditSaveFileAs();

protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);

private:
    void loadSettings();
    void saveSettings();

    QString mySettingsFile;

public:
    ChildWindow *designerWindow;
    ChildWindowEditor *editorWindow;
    ChildWindowProperty *propertyWindow;
    ChildWindowComponents *componentsWindow;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
