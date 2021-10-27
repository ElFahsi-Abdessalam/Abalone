#include "marble.h"


marble::marble(int dx ,
               int dy ,Color color)   : QGraphicsPolygonItem(nullptr),
    dx(dx), dy(dy),color(color),
    mouseover(false), selected(false), moved(false){

    double rad = 50;
    //Espace entre hexagone horit
    double spaceHorizontal = sqrt(3)*rad;

    double spaceVertical = -1.5*rad;

    double horizontalShift = 0.;

    double verticalShift = 0.;
    double horizontalPos = 0.;

    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4/6;

    if(dx%2==0){
       horizontalShift= -7.5*spaceHorizontal;
       verticalShift =(5-dx)*spaceVertical;
    }else{
        horizontalShift= -8*spaceHorizontal;
        verticalShift =(5-dx)*spaceVertical;
    }

    if(dx%2==0){
        horizontalPos = dy/2;
    }else{
        horizontalPos = (dy/2)+1;
    }


double finalY = horizontalShift+spaceHorizontal*horizontalPos;
double finalX = verticalShift;

    QPolygonF polygon;
    auto&& corners = orbit({finalY, finalX},6, 20., piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}
 double marble::getDx(){
    return this->dx;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void marble::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
   /* if(selected)
    {
        QPen pen(Qt::blue, 5);
        painter->setPen(pen);
        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else*
    {*/
         QPen pen(Qt::blue, 1);


        painter->setPen(pen);

        QBrush brush;
       // brush.setColor(Qt::cyan);
        if(this->color ==BLACK){
            brush.setColor(Qt::black);
        }else{
             brush.setColor(Qt::white);
        }

        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
   // }
    painter->drawPolygon(polygon());
}

void marble::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void marble::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void marble::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    moved = false;
    selected = !selected;

    update();
    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

void marble::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void marble::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}
#pragma GCC diagnostic pop
