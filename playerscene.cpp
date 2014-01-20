
#include "playerscene.h"
#include <QtGui>

PlayerScene::PlayerScene(QObject *parent) :
    QGraphicsScene(parent)
{
    cardSize=3;
    wid=6;
    high=15;


    setSceneRect(0,0,wid,high);
    //setStyle(QStyle::SE_ProgressBarGroove);
    gray.setRgba(1001515);
    active=0;
    cardsNum=0;
    special=0;
    real=0;
    last=0;


}


void PlayerScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (active){
        setBackgroundBrush(Qt::white);
        active=false;
        last=false;
    }
    else{
        setBackgroundBrush(Qt::lightGray);
        active=true;



    }
    emit sendToActive();


}
bool PlayerScene::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::TouchUpdate:
    {
        QList<QTouchEvent::TouchPoint> touchPoints = static_cast<QTouchEvent *>(event)->touchPoints();
       // if (touchPoints.size()==2){
            QVector<QPointF> bf;
            if (active){
                setBackgroundBrush(Qt::white);
                active=false;
                last=false;
            }
            else{
                setBackgroundBrush(Qt::lightGray);
                active=true;



            }
            emit sendToActive();

        //}
        break;
    }
    default:
        //return QObject::event(event);
        return QGraphicsScene::event(event);
    }
    return true;
}

void PlayerScene::redraw(){
     QString xx,y;
   setSceneRect(0,0,wid,high);
   float p=high/1.8;
   int q=wid/5.0;
   if(p>q)
       cardSize=q;
   else cardSize=p;
   QVector <QGraphicsItem*>  n=items().toVector();
   int x=0;
   while (x!=n.size()){
       removeItem(n[x]);

       x++;
   }
    draw(text,cardMax);
    for(int i=0;i<cardsValues.size();i++){
        QString name=":/pictures/pictures/"+xx.setNum(cardsValues[i].x()+1)+y.setNum(cardsValues[i].y()+1)+".jpg";
        QPixmap image (name);
        if(!special){
        addPixmap(image.scaled(cardSize,cardSize))->setPos(i*cardSize,cardSize);

        }
        else
        {
            addPixmap(image.scaled(cardSize,cardSize))->setPos(0,cardSize);

        }
    }
}
void PlayerScene::disActive(){
    setBackgroundBrush(Qt::white);
    active=false;
    last=false;

}

void PlayerScene::cleart(){
    QVector <QGraphicsItem*>  n=items().toVector();
    int x=0;
    while (x!=n.size()){
        removeItem(items().at(0));
        x++;
    }
    draw(text,cardMax);
    active=0;
    last=0;
    setBackgroundBrush(Qt::white);

    cardsNum=0;
    cardsValues.clear();
}
void PlayerScene::recive(){
             setBackgroundBrush(Qt::lightGray);
             active=true;
             last=true;
             }


void PlayerScene::setcard(QPoint value){
    if(real&&value.x()&&value.y()||!value.x()&&!value.y()||!real){
    QPoint f(0,0);
    if(cardsValues.size()==cardMax&&active&&!special){
        active=0;
        setBackgroundBrush(Qt::white);
        last=0;
        emit sendNext();
    }
    if(value==f)
        cleart();
    if(special&&active){
    cleart();
    QString x,y;
    cardsValues.push_back(value);
    QString name=":/pictures/pictures/"+x.setNum(value.x()+1)+y.setNum(value.y()+1)+".jpg";
    QPixmap image (name);
    addPixmap(image.scaled(cardSize,cardSize))->setPos(0,cardSize);
    //emit cardSetted(value,special);
    emit sendNext();
    }
    if(active&&cardsValues.size()!=cardMax&&!special)
    {QString x,y;
    QString name=":/pictures/pictures/"+x.setNum(value.x()+1)+y.setNum(value.y()+1)+".jpg";
    QPixmap image (name);
    addPixmap(image.scaled(cardSize,cardSize))->setPos(cardsNum*cardSize,cardSize);
    cardsNum+=1;
    cardsValues.push_back(value);
    if (value!=f)
    emit cardSetted(value,special);
    }

}}
 void PlayerScene::draw(QString txt, int max){
    text=txt;
    cardMax=max;
    addText(text)->setPos(0,0);
 }
