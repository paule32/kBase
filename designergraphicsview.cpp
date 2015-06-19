#include <QObject>
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QVector>

#include "designerresizer.h"
#include "designergraphicsview.h"

DesignerGraphicsView::DesignerGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(
                qreal(0),
                qreal(0),
                qreal(width()),
                qreal(height()),
                this);
    scene->setSceneRect(0,0,800,600);
    this->setScene(scene);
    this->scale(1,1);
    this->scroll(0,0);
    this->setTransformationAnchor(QGraphicsView::NoAnchor);

    drag_item = nullptr;

    item1 = new DesignerItem; item1->view = this;
    item2 = new DesignerItem; item2->view = this;

    item1->setGeometry(0,0,100,100);
    item2->setGeometry(0,0,100,100);

    resizer = new DesignerResizer;
    resizer->hide();

    scene->addItem(resizer);

    proxy1 = scene->addWidget(item1);
    proxy1->setPos(50,50);
    proxy1->setFlag(QGraphicsItem::ItemIsMovable,true);
    proxies << proxy1;
    item_objects[item1] = proxy1;

    proxy2 = scene->addWidget(item2);
    proxy2->setPos(70,70);
    proxy2->setFlag(QGraphicsItem::ItemIsMovable,true);
    proxies << proxy2;
    item_objects[item2] = proxy2;
}

void DesignerGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (item_objects[drag_item])
    {
        QPointF p = this->mapToScene(event->pos());
        item_objects[drag_item]->setPos(p-drag_item->m_pos);

        QPointF p2 = p;
        p2.setX(p2.x()-4.0);
        p2.setY(p2.y()-4.0);

        resizer->setPos(p2-drag_item->m_pos);
    }
}

void DesignerGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    drag_item = nullptr;
}

