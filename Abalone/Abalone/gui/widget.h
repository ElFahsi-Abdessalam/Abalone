#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Game.h"

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(Position position,Color color,QWidget *parent = nullptr);
    ~widget();
    /*!
     * \brief getPosition getter of the position of the marble.
     * \return the position of the marble.
     */
    inline Position getPosition();
private slots:
    /*!
     * \brief on_pushButton_clicked highlights the selected marble
     * and emmits a signal.
     */
    void on_pushButton_clicked();

signals :
 /*!
 * \brief pressed emmits a signal.
 */
void pressed();
private:
    Ui::widget *ui;
    Position position;
    Color color;
};

Position widget::getPosition(){
    return position;
}
#endif // WIDGET_H
