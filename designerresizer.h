#ifndef DESIGNERRESIZER_H
#define DESIGNERRESIZER_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "designergraphicsview.h"

class DesignerResizer : public QGraphicsRectItem
{
public:
    explicit DesignerResizer(QGraphicsRectItem *parent = 0);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

    int xpos;
    int ypos;

    int width;
    int height;
};

#endif // DESIGNERRESIZER_H

