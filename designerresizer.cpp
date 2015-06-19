#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include <QGraphicsRectItem>

#include "designerresizer.h"
#include "designergraphicsview.h"

DesignerResizer::DesignerResizer(QGraphicsRectItem *parent) :
    QGraphicsRectItem(parent)
{
    width = 106;
    height = 106;
    xpos = 0;
    ypos = 0;

    setRect(xpos,ypos, width,height);

    setPen(QPen(Qt::red));
    setBrush(Qt::yellow);
}

void DesignerResizer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainter *p = painter;
    QGraphicsRectItem::paint(painter,option,widget);

    QColor cb = Qt::black;

    p->fillRect(xpos,ypos,5,5,cb);
    p->fillRect(width-5,ypos+0,5,5,cb);
    p->fillRect(xpos,height-5,5,5,cb);
    p->fillRect(width-5,height-5,5,5,cb);
}
