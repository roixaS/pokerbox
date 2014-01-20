#ifndef REFERIE_H
#define REFERIE_H
#include <QVector>
#include <QPoint>

class Referie
{
public:
    Referie();

    int detCombine(QVector<QPoint> &, QPoint &c);//determine combine

    QVector<QPoint> sort(QVector<QPoint> &xx);//biggest card is last

    int refer(QVector<QPoint>, QVector<QPoint>);//final refer who win
    //0 loose,1 tie ,2 win
    int referKicker(QVector<QPoint> &,QVector<QPoint> &,QPoint ,QPoint,int sim);//for refering similar combines
    //(i,j) i it is a value of a first special card, pare, trip, kare,if nothing i=0
    //j it is a value of second special card, only second pare,if nothing j=0
    //sim is index of combine

    int baseRefer(QVector<QPoint>,QVector<QPoint>);//base final refer who win



    QPoint isKicker(QVector<QPoint> & );//return biggerst card

    QPoint isPare(QVector<QPoint> &);//!!!!!!!!

    QPoint isTwoPares(QVector<QPoint> &);//return point (i,j) i biggerst pare index

    QPoint isTrip(QVector<QPoint> &);//!!

    QPoint isStrate(QVector<QPoint>);//return i biggerst strate card (i,j)

    QPoint isFlash(QVector<QPoint> &);//return i biggerst flash card (i,j)

    QPoint isFullHouse(QVector<QPoint> &  );//return (i,j) i trip ,j pare

    QPoint isKare(QVector<QPoint> &);//!!!

    QPoint isRoyaleFlash(QVector<QPoint> &);//return card of biggerst royale flash(i,j)
};

#endif // REFERIE_H
