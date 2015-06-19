#ifndef PROPERTYFORM_H
#define PROPERTYFORM_H

#include <QWidget>

namespace Ui {
class PropertyForm;
}

class PropertyForm : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyForm(QWidget *parent = 0);
    ~PropertyForm();

protected:
    void resizeEvent(QResizeEvent *evt);

private:
    Ui::PropertyForm *ui;
};

#endif // PROPERTYFORM_H
