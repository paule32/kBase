#ifndef DESIGNERGRAPHICSVIEW_H
#define DESIGNERGRAPHICSVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "designeritem.h"
#include "designerresizer.h"

class DesignerResize;

extern class QVector<QGraphicsProxyWidget *> proxies;

class DesignerGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit DesignerGraphicsView(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QGraphicsScene *scene;

public:
    DesignerItem *drag_item;
    class DesignerResizer *resizer;

    QGraphicsProxyWidget *proxy1;
    QGraphicsProxyWidget *proxy2;

    DesignerItem *item1;
    DesignerItem *item2;

    QVector<QGraphicsProxyWidget *> proxies;
    QMap<DesignerItem*, QGraphicsProxyWidget*> item_objects;
};

#endif // DESIGNERGRAPHICSVIEW_H
