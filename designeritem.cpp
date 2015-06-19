#include <QGraphicsProxyWidget>
#include "designergraphicsview.h"
#include "designeritem.h"

DesignerItem::DesignerItem(QWidget *p, Qt::WindowFlags f)
  : QWidget(p,f)
{
    _p = p;
}

DesignerItem::~DesignerItem() { }

void DesignerItem::paintEvent(QPaintEvent *event)
{
    QRect rectangle(0,0, 97,97);
    QBrush red(Qt::red);

    p.begin(this);
    p.drawRect(rectangle);
    p.end();
}

void DesignerItem::mousePressEvent(QMouseEvent *event)
{
    view->drag_item = this;
    qDebug() << "MausPress:" << this;

    m_pos = event->localPos();

    view->resizer->show();
    view->resizer->setZValue(1000);

    for (int i = 0; i < view->proxies.size(); ++i)
    {
        QList <DesignerItem*> keys = view->item_objects.keys(view->proxies[i]);
        if (keys.size() != 0)
        {
            if (keys[0] == view->item1) view->item1->raise(); else
            if (keys[0] == view->item2) view->item2->raise();
        }
    }

    QWidget::mousePressEvent(event);
}

void DesignerItem::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << x();
    QWidget::mousePressEvent(event);
}
