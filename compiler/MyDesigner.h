#ifndef MYDESIGNER_H
#define MYDESIGNER_H

#include <QObject>
#include <QApplication>
#include <QCursor>
#include <QHeaderView>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QPaintEvent>
#include <QStyledItemDelegate>
#include <QPushButton>
#include <QTreeWidget>

QT_BEGIN_NAMESPACE

enum DesignerObjects
{
    DesignerObject_None,
    DesignerObject_EntryField,
    DesignerObject_PushButton
};

extern DesignerObjects placeObject;

class MyTreeWidget: public QTreeWidget
{
public:
    MyTreeWidget(QWidget *parent=0) : QTreeWidget(parent)
    {
        set_items(parent);
    }
    void set_items(QWidget *p);

protected:
    virtual void paintEvent(QPaintEvent *event);
};


class MyDesigner: public QWidget
{
    Q_OBJECT
public:
    MyDesigner(QWidget *parent=0) : QWidget(parent)
    {
        placeObject = DesignerObject_None;
    }

    QList<QString>  objectNames;
    QWidget       *activeObject;
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
};


class MyDesignerPushButton: public QPushButton
{
    Q_OBJECT
public:
    MyDesignerPushButton(QWidget *parent=0) : QPushButton(parent)
    {
        MyDesigner *w;
        if ((w = qobject_cast<MyDesigner*>(parent)) != NULL)
        {
            w = qobject_cast<MyDesigner*>(parent);
            w->objectNames << QString("PushButton_%1").arg(count);
            w->activeObject = this;
            count++;

            setMouseTracking(true);
            isDown = false;
            isResize = false;
            isResize1 = false;
        }
    }

    static int count;

private:
    int o_posx, o_posX;
    int o_posy, o_posY;
    int o_width;
    int o_height;

    bool isDown;
    bool isResize;
    bool isResize1;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
};


class MyDesignerEntryField: public QLineEdit
{
    Q_OBJECT
public:
    MyDesignerEntryField(QWidget *parent=0) : QLineEdit(parent)
    {
        MyDesigner *w;
        if ((w = qobject_cast<MyDesigner*>(parent)) != NULL)
        {
            w = qobject_cast<MyDesigner*>(parent);
            w->objectNames << QString("EntryField_%1").arg(count);
            w->activeObject = this;
            count++;

            setMouseTracking(true);
            isDown = false;
            isResize = false;
            isResize1 = false;
            inDesigner = true;
        }
    }

    MyDesignerEntryField(MyTreeWidget *parent=0) : QLineEdit(parent)
    {
        inDesigner = false;
    }

    static int count;
    bool hasFocus;

private:
    int o_posx, o_posX;
    int o_posy, o_posY;
    int o_width;
    int o_height;

    bool isDown;
    bool isResize;
    bool isResize1;
    bool inDesigner;

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *event);
    virtual void focusOutEvent(QFocusEvent *event);
};

class NoEditDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    NoEditDelegate(QObject* parent=0): QStyledItemDelegate(parent)
    {
        tree = static_cast<MyTreeWidget*>(parent);
    }

    MyTreeWidget *tree;

    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};

#endif // MYDESIGNER_H
