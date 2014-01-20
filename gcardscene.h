#ifndef GCARDSCENE_H
#define GCARDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class GcardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GcardScene(QObject *parent = 0);
    float picSize;
    QVector <QPoint> values;//ГЄГ Г°ГІГ» ГЁ Г¬Г Г±ГІГЁ
    QVector <QPoint> choosedCards;//Г­ГҐГ«ГјГ§Гї Г¤ГўГ Г¦Г¤Г» ГўГ»ГЎГЁГ°Г ГІГј ГЄГ Г°ГІГі
    void clearAll();
    void setCardOnScene();
    float wight;

    float hight;
    void redraww(float,float);
protected:

void  mousePressEvent ( QGraphicsSceneMouseEvent  *eventt );
bool event(QEvent *event);

signals:
    void choosen(QPoint );
    void ckickedOnScene();



public slots:
    void removeCard(QPoint,bool);





};

#endif // GCARDSCENE_H
