#ifndef __DESIGNER_ITEM_H__
#define __DESIGNER_ITEM_H__

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGraphicsRectItem>

class DesignerItem : public QWidget
{
  Q_OBJECT

public:
    explicit DesignerItem(QWidget *p = 0, Qt::WindowFlags f = 0);
    ~DesignerItem();

    QPointF m_pos;
    QWidget *_p;

    class DesignerGraphicsView *view;

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent * event);

private:
    QPainter p;
};

#endif

