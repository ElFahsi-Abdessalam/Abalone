#ifndef MARBLE_H
#define MARBLE_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <iostream>
#include <cmath>

#include "point.hpp"
#include "Color.h"
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

class marble  :public QGraphicsPolygonItem{
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation
protected:
    double dx, dy;//hexagon radius, coordinate (x,y) of center
    Color color;
    bool mouseover, selected, moved;//mouse interaction booleans
public :
    marble(int dx = 0,
           int dy = 0,Color =WHITE);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);
protected: double getDx();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * event);
};





#endif // MARBLE_H
