#ifndef COMPONENTSFORM_H
#define COMPONENTSFORM_H

#include <QWidget>

enum newObject_onDesigner {
    odNone,
    odPushButton,
    odEntryfield
};

extern newObject_onDesigner current_DegignerObject;

namespace Ui {
class ComponentsForm;
}

class ComponentsForm : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentsForm(QWidget *parent = 0);
    ~ComponentsForm();

protected:
    void resizeEvent(QResizeEvent *evt);

private slots:
    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

public:
    Ui::ComponentsForm *ui;
};

#endif // COMPONENTSFORM_H
