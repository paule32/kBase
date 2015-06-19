#ifndef DESIGNERFORM_H
#define DESIGNERFORM_H

#include <QWidget>
#include "designergraphicsview.h"

namespace Ui {
class DesignerForm;
}

class DesignerForm : public QWidget
{
    Q_OBJECT

public:
    explicit DesignerForm(QWidget *parent = 0);
    ~DesignerForm();

protected:
    void resizeEvent(QResizeEvent *evt);

public:
    void loadsettings();
    void savesettings();

    Ui::DesignerForm *ui;
};

#endif // DESIGNERFORM_H
