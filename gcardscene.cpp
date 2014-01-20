#include <QtGui>
#include "gcardscene.h"

GcardScene::GcardScene(QObject *parent) :
    QGraphicsScene(parent)
{
    picSize=30;
    wight=150;
    hight=420;
   setCardOnScene();


}
void GcardScene::redraww(float p,float q){
   //

    p/=5.0;
    q/=14.0;
   if(p<q)
        picSize=p;
   if(p>q)
       picSize=q;
   //else picSize=30;
   QVector <QGraphicsItem*>  n=items().toVector();
   int x=0;
   while (x!=n.size()){
       removeItem(items().at(0));
       x++;
   }
   setCardOnScene();



}

bool GcardScene::event(QEvent *event)
{
    switch (event->type()) {

    case QEvent::TouchEnd:
    {
        QList<QTouchEvent::TouchPoint> touchPoints = static_cast<QTouchEvent *>(event)->touchPoints();
       // if (touchPoints.size()==2){
            QVector<QPointF> bf;
        foreach (const QTouchEvent::TouchPoint &touchPoint, touchPoints) {
                    bf.push_back( touchPoint.scenePos());
                    }
        QPointF po=bf.last();
        int x,y,t=0;
        QPoint pos=po.toPoint();
        y=pos.x()/picSize;
        x=pos.y()/picSize;
        if(x>13||y>4)
            t=1;
        QPoint value(x,y);
        QPoint f(0,0);
        if(f==value){
            clearAll();
        }
        int size =choosedCards.size();
        for(int i=0;i<size;i++){
            if(choosedCards[i]==value)
                t=1;}
        if(!t){
        emit choosen(value);
        emit ckickedOnScene();
        }


        //}
        break;
    }
    default:
        return QObject::event(event);
        //return QGraphicsScene::event(event);
    }
    return true;
}

void GcardScene::setCardOnScene(){


setSceneRect(0,0,picSize*5,picSize*14);






    for(int i=0;i<14;i++){
        for(int j=0;j<5;j++){
            QPoint bf(i,j);
            int t=0;
            for(int k=0;k<choosedCards.size();k++)
            {
                if(bf==choosedCards[k])
                    t++;
            }
            if(!t){
            QString x,y;
            QString name=":/pictures/pictures/"+x.setNum(i+1)+y.setNum(j+1)+".jpg";

            QPixmap image (name);
            if(!image.isNull())
            addPixmap(image.scaled(picSize,picSize))->setPos(j*picSize,i*picSize);

        }}
    }
}
 void GcardScene::clearAll(){
    choosedCards.clear();
    QVector <QGraphicsItem*>  n=items().toVector();
    int x=0;
    while (x!=n.size()){
        removeItem(items().at(0));
        x++;
    }
    setCardOnScene();
 }
void GcardScene:: mousePressEvent (QGraphicsSceneMouseEvent * eventt ){

    QPointF pos(eventt->scenePos());
    int x,y,t=0;
    y=pos.x()/picSize;
    x=pos.y()/picSize;
    if(x>13||y>4)
        t=1;
    QPoint value(x,y);
    QPoint f(0,0);
    if(f==value){
        clearAll();
    }
    int size =choosedCards.size();
    for(int i=0;i<size;i++){
        if(choosedCards[i]==value)
            t=1;}
    if(!t){
    emit choosen(value);
    emit ckickedOnScene();
    }
}
void GcardScene::removeCard(QPoint P, bool SP){
    double x,y,t=0;

    x=(P.y()+1/2)*picSize;
    y=(P.x()+1/2)*picSize;
    QPointF pos(x,y);
    QTransform tpo;
    int size =choosedCards.size();
    for(int i=0;i<size;i++){
        if(choosedCards[i]==P)
            t=1;}
    if(!t&&!SP){
    itemAt(pos,tpo)->setVisible(false);
    choosedCards.push_back(P);

    }
}
