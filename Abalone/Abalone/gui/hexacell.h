#ifndef HEXACELL_H
#define HEXACELL_H

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
#include "mainwindow.h"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

class HexaCell  :  public QObject,public QGraphicsPolygonItem
{
    Q_OBJECT
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

protected:
    double dx, dy;//hexagon radius, coordinate (x,y) of center
    bool mouseover, selected, moved;//mouse interaction booleans

public:
    //MainWindow *mainwindows =nullptr
    HexaCell(int dx =0,
             int dy =0);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);
    int getXFromChar(char c);
private:

    void convertDxDY(int &dx,int &dy);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * event);
signals:
    void sendValue(Position & pos);
};

#endif // HEXACELL_H
