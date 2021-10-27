#include "hexacell.h"

MainWindow * main=nullptr;



double const HexaCell::zValMax = 10000;//arbitrary
                   // MainWindow *mainwindows
HexaCell::HexaCell( int dx, int dy )
    : QGraphicsPolygonItem(nullptr),
      dx(dx), dy(dy),
      mouseover(false), selected(false), moved(false)
{
    //main =mainwindows;

    double rad = 50;
    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4/6;
    convertDxDY(dx,dy);

    QPolygonF polygon;
    auto&& corners = orbit({dx, dy},6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}


void HexaCell::convertDxDY(int &dx,int &dy){
    double rad =50;
    //Espace entre hexagone horit
    double spaceHorizontal = sqrt(3)*rad;// space taken horizontally by a hexagon = the space between centers of two adjacent hexagons (same line)

    double spaceVertical = -1.5*rad;// space taken between two lines in terms of centers of hexagons

    double horizontalShift = 0.;

    double verticalShift = 0.; // position of line compared to center of gameboard

    double horizontalPos = 0.;//Position compared to the first on the left of the line
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


    dx = horizontalShift+spaceHorizontal*horizontalPos;
    dy = verticalShift;

}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    if(selected)
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
    else
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

    moved = false;
    selected = !selected; //I'd like to put this in "released"

     //update();

    //relaunches the event in order to allow dragging
    //QGraphicsItem::mousePressEvent(event);

    Position p =Position(dx,dy);
    emit sendValue(p);
}

void HexaCell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //why isn't this ever fired ?
}

void HexaCell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void HexaCell::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}


#pragma GCC diagnostic pop
