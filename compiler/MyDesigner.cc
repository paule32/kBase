#include "MyDesigner.h"

DesignerObjects placeObject;

int  MyDesignerPushButton::count = 0;
int  MyDesignerEntryField::count = 0;

void MyDesigner::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int rx, ry;
    int gridsize = 5;

    painter.setBrush(Qt::SolidPattern);

    // -------------
    // draw grid ...
    // -------------
    for (rx = 0; rx < size().width(); rx += gridsize)
        for (ry = 0; ry < size().height(); ry += gridsize)
            painter.drawPoint(rx,ry);

    if (placeObject == DesignerObject_PushButton)
    {
        QWidget *w;
        if ((w = qobject_cast<MyDesignerPushButton*>(activeObject)) != NULL)
        {
            w = qobject_cast<MyDesignerPushButton*>(activeObject);
        }
    }
}

void MyDesigner::mousePressEvent(QMouseEvent *event)
{
    if (placeObject == DesignerObject_PushButton)
    {
        MyDesignerPushButton *btn = new MyDesignerPushButton(this);
        btn->setGeometry(event->x(),event->y(),100,30);
        btn->show();
    }
    else if (placeObject == DesignerObject_EntryField)
    {
        MyDesignerEntryField *edit = new MyDesignerEntryField(this);
        edit->setGeometry(event->x(),event->y(),100,30);
        edit->show();
    }

    repaint();
}

void MyDesignerPushButton::mouseMoveEvent(QMouseEvent *event)
{
    int xp = event->x();
    int yp = event->y();
    int rs = 5;

    if (isDown == true)
    {
        if (isResize1 == true)
        {
            if (xp < 0)
                resize(o_width  + (xp+o_posX),
                       o_height + (yp+o_posY)); else
                resize(o_width  - (xp-o_posX),
                       o_height - (yp-o_posY));

            move(o_posX,o_posY);

            o_posX = geometry().x();
            o_posY = geometry().y();

            return;
        }
        else if (isResize == true)
        {
            resize(xp,yp);
        } else
        setGeometry(QRect(
                    this->geometry().x()+xp-o_posx,
                    this->geometry().y()+yp-o_posy,
                    size().width(),
                    size().height()));
        setCursor(QCursor(Qt::ArrowCursor));
        update();
    }
    else {
        if ((xp >= 0                  && xp <= rs)
        &&  (yp >= 0                  && yp <= rs))
        {
            setCursor(QCursor(Qt::SizeFDiagCursor));
            isResize1 = true;
        }
        else
        if ((xp >= size().width ()-rs && xp <= size().width ())
        &&  (yp >= size().height()-rs && yp <= size().height()))
        {
            setCursor(QCursor(Qt::SizeFDiagCursor));
            isResize = true;
        }
    }
}

void MyDesignerPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        isDown = false;
        isResize = false;
        isResize1 = false;
    }
}

void MyDesignerPushButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    QPainter p(this);

    p.drawRect(0,0,3,3);
    p.drawRect(0,height()-3,3,3);
    p.drawRect(width()-3,0,3,3);
    p.drawRect(width()-3,height()-3,3,3);

    p.drawRect(((width())/2)-3,0,3,3);
    p.drawRect(((width())/2)-3,height()-3,3,3);
}


void MyDesignerPushButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPoint pos = event->pos();

        o_posx = pos.x();
        o_posy = pos.y();

        o_posX = geometry().x();
        o_posY = geometry().y();

        o_width = width();
        o_height = height();

        isDown = true;
    }
}



void MyDesignerEntryField::mouseMoveEvent(QMouseEvent *event)
{
    if (!inDesigner)
    {
        QLineEdit::mouseMoveEvent(event);
        return;
    }

    int xp = event->x();
    int yp = event->y();
    int rs = 5;

    if (isDown == true)
    {
        if (isResize1 == true)
        {
            if (xp < 0)
                resize(o_width  + (xp+o_posX),
                       o_height + (yp+o_posY)); else
                resize(o_width  - (xp-o_posX),
                       o_height - (yp-o_posY));

            move(o_posX,o_posY);

            o_posX = geometry().x();
            o_posY = geometry().y();

            return;
        }
        else if (isResize == true)
        {
            resize(xp,yp);
        } else
        setGeometry(QRect(
                    this->geometry().x()+xp-o_posx,
                    this->geometry().y()+yp-o_posy,
                    size().width(),
                    size().height()));
        setCursor(QCursor(Qt::ArrowCursor));
        update();
    }
    else {
        if ((xp >= 0                  && xp <= rs)
        &&  (yp >= 0                  && yp <= rs))
        {
            setCursor(QCursor(Qt::SizeFDiagCursor));
            isResize1 = true;
        }
        else
        if ((xp >= size().width ()-rs && xp <= size().width ())
        &&  (yp >= size().height()-rs && yp <= size().height()))
        {
            setCursor(QCursor(Qt::SizeFDiagCursor));
            isResize = true;
        }
    }
}

void MyDesignerEntryField::mouseReleaseEvent(QMouseEvent *event)
{
    if (!inDesigner)
    {
        QLineEdit::mouseReleaseEvent(event);
        return;
    }
    else if (event->button() & Qt::LeftButton)
    {
        isDown = false;
        isResize = false;
        isResize1 = false;
    }
}

void MyDesignerEntryField::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);
    if (!inDesigner) return;

    QPainter p(this);

    p.drawRect(0,0,3,3);
    p.drawRect(0,height()-3,3,3);
    p.drawRect(width()-3,0,3,3);
    p.drawRect(width()-3,height()-3,3,3);

    p.drawRect(((width())/2)-3,0,3,3);
    p.drawRect(((width())/2)-3,height()-3,3,3);
}


void MyDesignerEntryField::mousePressEvent(QMouseEvent *event)
{
    if (!inDesigner)
    {
        QLineEdit::mousePressEvent(event);
        return;
    }
    else if (event->button() == Qt::LeftButton)
    {
        QPoint pos = event->pos();

        o_posx = pos.x();
        o_posy = pos.y();

        o_posX = geometry().x();
        o_posY = geometry().y();

        o_width = width();
        o_height = height();

        isDown = true;
    }
}

void MyDesignerEntryField::focusInEvent (QFocusEvent *event) { hasFocus = true;  }
void MyDesignerEntryField::focusOutEvent(QFocusEvent *event) { hasFocus = false; }


QWidget* NoEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return 0;
}

void NoEditDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    //QStyledItemDelegate::paint(painter, option, index);

    QStyleOptionViewItemV4 newOption(option);
    initStyleOption(&newOption, index);

    painter->save();

    newOption.state &= ~QStyle::State_Selected;
    newOption.state &= ~QStyle::State_HasFocus;
    newOption.state &= ~QStyle::State_MouseOver;

    newOption.widget->style()->drawControl(QStyle::CE_ItemViewItem, &newOption, painter);

    painter->translate(newOption.rect.left()-50,  newOption.rect.top());
    QRect clip(0, 1,   newOption.widget->width(), newOption.rect.height());

    QString    txt = newOption.text;
    MyDesignerEntryField* edt = tree->findChild<MyDesignerEntryField*>("EditPageNoEdior");

    if (txt == "pageno" && edt->hasFocus)
    {
        painter->fillRect(clip, QColor(120,200,200));
        painter->drawText(42,15, txt);
    }
    else
    {
        painter->fillRect(clip, QColor(255,255,255));
        painter->drawText(52,13, txt);

        if (txt != "pageno")
        {
            painter->setFont(QFont("Arial",8));
            painter->drawText(35,12,"[+]");
        }
    }

    painter->restore();
}

void MyTreeWidget::set_items(QWidget *p)
{
    QTreeWidgetItem *__qtreeitem  = new QTreeWidgetItem(this);
    QTreeWidgetItem *__qtreeitem1 = new QTreeWidgetItem((__qtreeitem));
    __qtreeitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setRootIsDecorated(true);
    setAllColumnsShowFocus(false);
    setFont(QFont("Arial",10));

    header()->setDefaultSectionSize(100);

    QTreeWidgetItem *___qtreeitem = headerItem();
    ___qtreeitem->setText(1, "Wert");
    ___qtreeitem->setText(0, "Eigenschaft");

    NoEditDelegate *ne = new NoEditDelegate(this);

    setSortingEnabled(false);
    setItemDelegateForColumn(0, ne);

    QTreeWidgetItem *___qtreeitem1 = (topLevelItem(0));
    ___qtreeitem1->setText(0, "Anzeige");


    QTreeWidgetItem *___qtreeitem2 = (___qtreeitem1->child(0));
    ___qtreeitem2->setText(1, "1");
    ___qtreeitem2->setText(0, "pageno");
    ___qtreeitem2->setSelected(false);
    MyDesignerEntryField *pe = new MyDesignerEntryField(this);
    pe->setObjectName("EditPageNoEdior");
    setItemWidget(___qtreeitem2,1,pe);

    QTreeWidgetItem     *___qtreeitem3 = new QTreeWidgetItem(this);
    insertTopLevelItem(0,___qtreeitem3);
    QTreeWidgetItem     *___qtreeitem4 = topLevelItem(1);

    ___qtreeitem4->setText(0, "Bearbeiten");
}

void MyTreeWidget::paintEvent(QPaintEvent *event)
{
    QTreeWidget::paintEvent(event);

    int pHeight = font().pointSize();
    int pWidth  = columnWidth(0);

    QPainter p;
    p.begin(viewport());

    int rc = 10;
    int py = 0;

    for(int i = 0; i < rc; i++)
    {
        p.drawRect(1,py,pWidth-2,py+pHeight+7);
        p.drawRect(pWidth-1,py,columnWidth(1),py+pHeight+7);
        py += pHeight+7;
    }

    p.end();
}
