#ifndef PLAYERSCENE_H
#define PLAYERSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QTouchEvent>

class PlayerScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PlayerScene(QObject *parent = 0);
    int cardsNum;
    QVector <QPoint> cardsValues;
    int cardSize;
    int cardMax;
    QColor gray;
    QString text;
    bool active;
    bool last;
    bool real;//пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ
    bool special;//пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ
    void draw(QString,int);
    void cleart();
    void disActive();
    void redraw();
    float wid;
    float high;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool event(QEvent *event);
signals:
    void sendToActive();
    void cardSetted(QPoint,bool);
    void sendNext();

public slots:

    void setcard(QPoint );
    void recive();
    //void touchEvent(QEvent *);

    //void cleart();


};

#endif // PLAYERSCENE_H
