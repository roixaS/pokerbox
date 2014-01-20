#ifndef MATHER_H
#define MATHER_H
#include <QVector>
#include <QString>
#include <QPoint>
#include <QDebug>
#include <math.h>
#include "referie.h"
class Mather
{
public:
    Mather();
    Referie *r;

    QVector<QPoint> yourCards;
    QVector<QPoint> enemiesCards;
    QVector<QPoint> enemiesNotCards;
    QVector<QPoint> tableCards;
    QVector<QPoint> unknownCards;
    float chanseTie;//tie
    float chanseWin;
    float chanseLoose;
    QVector<QPoint> oppUnknCards;
    void makeoppUnknCards();//deternime probably opponents cards

    void makeoppTwoCard();
    void makeYourChanse();//need for river
    void makeYourChanseOneCard();//need for turn
    void makeYourChanseTwoCard();//need for flop
    void makeYourChanseThreeCard();//need for preflop
    QPoint buffCard;
    void refreshUnknownCards();
    float sumChanse(float ch,float N);//
    int numbPlayers;
    int totalCards;

    void refresh(QVector<QPoint> &, QVector<QPoint> &, QVector<QPoint> &, QVector<QPoint> &, QVector<QPoint> &);

    void makeAWin();


};

#endif // MATHER_H
