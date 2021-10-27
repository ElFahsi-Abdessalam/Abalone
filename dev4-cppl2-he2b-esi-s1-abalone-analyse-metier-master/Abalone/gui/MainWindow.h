#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*!
     * \brief updateCurrentPlayerLabel updates the display
     * of the current player
     * \param currPlayer the current player.
     */
    void updateCurrentPlayerLabel(QString currPlayer);
    /*!
     * \brief updateBlackPlayerScore updates the score of the
     * black player.
     * \param score the score of the black player.
     */
    void updateBlackPlayerScore(QString score);
    /*!
     * \brief updateWhitePlayerScore updateWhitePlayerScore updates the score of the
     * white player.
     * \param score the score of the white player.
     */
    void updateWhitePlayerScore(QString score);
    /*!
     * \brief updateErrorLabel indicates an error to the player.
     * \param msg the description of the error.
     */
    void updateErrorLabel(QString msg);

    /*!
    * \brief updateEndGameLabel indicates the winner
    * at the end of the game.
    * \param msg the message indicating the winner.
    */
    void updateEndGameLabel(QString msg);

private slots:
    /*!
     * \brief move Adds the position of the clicked marble in the
     * vector of marbles
     */
    void move();
    /*!
     * \brief on_pushButton_clicked validates the chosen marbles and
     * initiates a movement.
     */
    void on_pushButton_clicked();

    /*!
     * \brief on_pushButton_2_clicked resets the selected marbles.
     */
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Game _game;
    std::vector<Position>moveVector;
    void updateGameBoard();
};

#endif // MAINWINDOW_H
