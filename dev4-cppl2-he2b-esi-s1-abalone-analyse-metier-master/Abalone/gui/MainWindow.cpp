#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _game{Game()},
    moveVector{}
{
    ui->setupUi(this);
    QPixmap bg{":/img/board.png"};
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bg);
    this->setPalette(palette);

    for (int i=0;i<19 ;++i ) {
        for (int j=1;j<10 ;++j ) {
            Position pos{j,i};
            widget* w=new widget(pos,_game.getBoard().getCaseAtPosition(pos).getColorCase());
            ui->gridLayout->addWidget(w ,j,i);
            QObject::connect(w, SIGNAL(pressed()), this,//
                             SLOT(move()), Qt::UniqueConnection);//
        }
    }
    updateCurrentPlayerLabel("Current player is Black");
    updateBlackPlayerScore("Black remaining marbles : "+QString::number(_game.getPlayer1().getcmpt()));
    updateWhitePlayerScore("White remaining marbles :" +QString::number(_game.getPlayer2().getcmpt()));
}

void MainWindow::updateCurrentPlayerLabel(QString currPlayer){
    ui->current->setText(currPlayer);
}
void MainWindow::updateBlackPlayerScore(QString score){
    ui->black->setText(score);
}
void MainWindow::updateWhitePlayerScore(QString score){
    ui->white->setText(score);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move(){
    bool canAdd=true;
    widget * w= qobject_cast<widget *>(QObject::sender());
    for (auto pos :moveVector) {
        if(pos==w->getPosition())
            canAdd=false;
    }
    if(canAdd)
        moveVector.push_back(w->getPosition());
}
void MainWindow::updateEndGameLabel(QString msg){
    ui->endGame->setText(msg);
}

void MainWindow::on_pushButton_clicked()
{
    updateErrorLabel("");
    static auto player =_game.getPlayer1();
    bool ok=true;
    for (auto pos : moveVector) {
        if(_game.getBoard().getCaseAtPosition(pos).getColorCase()!=player.getPlayerColor()&&
                _game.getBoard().getCaseAtPosition(pos).getColorCase()!=EMPTY){
            updateErrorLabel("The wrong player is playing");
            ok=false;
            moveVector.clear();
        }
    }
    if(ok){
        if(moveVector.size()==2||moveVector.size()==3){
            _game.move(moveVector,player);
            moveVector.clear();
            player=player.getPlayerColor()==_game.getPlayer1().getPlayerColor()?_game.getPlayer2():_game.getPlayer1();
            updateCurrentPlayerLabel(player.getPlayerColor()==BLACK?"Current player is Black":"Current player is White");
            updateBlackPlayerScore("Black remaining marbles : "+QString::number(_game.getPlayer1().getcmpt()));
            updateWhitePlayerScore("White remaining marbles :" +QString::number(_game.getPlayer2().getcmpt()));
        }

        if(_game.gameIsFinish()){
           updateEndGameLabel(player.getPlayerColor()==BLACK?"WHITE HAS WON !!!!":"BLACK HAS WON !!!!");
            this->setDisabled(true);
        }
    }
    updateGameBoard();
}
void MainWindow::updateGameBoard(){

    while(ui->gridLayout->layout()->count() > 0) {
        delete  ui->gridLayout->takeAt(0)->widget();
    }
    for (int i=0;i<19 ;++i ) {
        for (int j=1;j<10 ;++j ) {
            Position pos{j,i};
            widget* w=new widget(pos,_game.getBoard().getCaseAtPosition(pos).getColorCase());
            ui->gridLayout->addWidget(w ,j,i);
            QObject::connect(w, SIGNAL(pressed()), this,
                             SLOT(move()), Qt::UniqueConnection);
        }
    }
}
void MainWindow::updateErrorLabel(QString msg){
    ui->erreur->setText(msg);
}

void MainWindow::on_pushButton_2_clicked()
{
    updateGameBoard();
    moveVector.clear();
}
