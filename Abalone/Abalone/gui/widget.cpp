#include "widget.h"
#include "ui_widget.h"

widget::widget(Position positon,Color color,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget),
    position{positon},
    color{color}
{
    ui->setupUi(this);
    ui->pushButton->setFixedHeight(50);
    ui->pushButton->setFixedWidth(50);
    ui->pushButton->setAutoFillBackground(true);
    if(color==BLACK){
        ui->pushButton->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(0, 0, 0)");
        QRect rect(0,0,22,22);
        QRegion region(rect, QRegion::Ellipse);
        ui->pushButton->setMask(region);
    }else if(color == WHITE){
        ui->pushButton->setStyleSheet("background-color: rgb(200, 200, 200); color: rgb(200, 200, 200)");
        QRect rect(0,0,22,22);
        QRegion region(rect, QRegion::Ellipse);
        ui->pushButton->setMask(region);
    }else if(color==EMPTY){
        ui->pushButton->setStyleSheet("background-color: rgb(122, 122, 122); color: rgb(122, 122, 122)");
        QRect rect(0,0,10,10);
        QRegion region(rect, QRegion::Ellipse);
        ui->pushButton->setMask(region);
    }else{
       ui->pushButton->setVisible(false);
    }
}

void widget::on_pushButton_clicked(){

    ui->pushButton->setStyleSheet("background-color: rgb(12, 200, 200); color: rgb(12, 200, 200)");
    emit pressed();

}

widget::~widget()
{
    delete ui;
}



