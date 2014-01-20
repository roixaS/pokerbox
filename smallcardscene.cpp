#include <QtGui>
#include "smallcardscene.h"

SmallCardScene::SmallCardScene(QObject *parent) :
    QGraphicsScene(parent)
{
    picSize=50;
    wight=150;
    hight=450;
    setCardOnScene();
    pushed=false;
    changed=false;


}
void SmallCardScene::redraww(float p,float q){
   //

    p/=2.0;
    q/=10.0;
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

bool SmallCardScene::event(QEvent *event)
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
        QPoint value;
        if(x>8||y>1)
            t=1;

        bool change=0;
            if(pushed){

                if(y==0){
                    if(x>4){

                        change=1;
                        value=QPoint((9-x),push.y());
                        //QPoint topleft=(x*picSize,y*picSize);
                        //QPoint botright((x+1)*picSize,(y+1)*picSize);
                        //QRect rect(topleft,botright);

                    }
                    else{

                        value=push;
                        change=1;
                    }
                }
                else{

                    change=1;
                    value=QPoint((13-x),push.y());}

                pushed=0;
                qDebug()<<value<<push;
            }

            else{
                if(y==0){

                    if(x<5){
                       baseClear();
                       QTransform tpo;
                       itemAt(pos,tpo)->setVisible(false);
                        change=1;
                        if(x==0)
                            value=QPoint(x,0);
                        else
                            value=QPoint(0,x);
                    }


                }
                if(change)
                push=value;
                pushed=1;

                }


            QPoint f(0,0);
            QPoint val=f;

            if(change)
            val=value;


            if(f==value&&change){
                clearAll();
            //



            }



            int size =choosedCards.size();
            for(int i=0;i<size;i++){
                if(choosedCards[i]==val)
                    t=1;}
            if(!t&&!pushed){
            emit choosen(val);
            emit ckickedOnScene();
        }


        //}
        break;
    }
    default:
        //return QObject::event(event);
        return QGraphicsScene::event(event);
    }
    return true;
}

void SmallCardScene::setCardOnScene(){
 QString x,y;
    setSceneRect(0,0,picSize*2,picSize*9);
    QString nullname=":/pictures/pictures/"+x.setNum(1)+y.setNum(1)+".jpg";
    QPixmap nullimage (nullname);//clear
    if(!nullimage.isNull())
    addPixmap(nullimage.scaled(picSize,picSize))->setPos(0,0);


    int ch=0;
    int pos=0;

    for(int i=0;i<2;i++){
        for(int j=0;j<9;j++){
            QString name;
            //QPoint bf(i,j);

            if(!i){
                if(ch<4){//masti

                    name=":/pictures/pictures/"+x.setNum(1)+y.setNum(j+2)+".jpg";
                    ch++;

                }
                else{//karty
                    name=":/pictures/pictures/"+x.setNum(9-j)+y.setNum(1)+".jpg";
                    if(j==8)
                        break;

                }
                QPixmap image (name);
                if(!image.isNull())
                addPixmap(image.scaled(picSize,picSize))->setPos(0,(j+1)*picSize);

             }
            else{//2 stolb
                name=":/pictures/pictures/"+x.setNum(14-j)+y.setNum(1)+".jpg";
                QPixmap image (name);
                if(!image.isNull())
                addPixmap(image.scaled(picSize,picSize))->setPos(picSize,(j)*picSize);

            }






        }
    }
}


 void SmallCardScene::clearAll(){
    choosedCards.clear();
    pushed=false;
    QVector <QGraphicsItem*>  n=items().toVector();
    int x=0;
    while (x!=n.size()){
        removeItem(items().at(0));
        x++;
    }
    setCardOnScene();
 }

void SmallCardScene::baseClear(){
    QVector <QGraphicsItem*>  n=items().toVector();
    int x=0;
    while (x!=n.size()){
        removeItem(items().at(0));
        x++;
    }
    setCardOnScene();

}

void SmallCardScene:: mousePressEvent (QGraphicsSceneMouseEvent * eventt ){

    QPointF pos(eventt->scenePos());
    int x,y,t=0;
    y=pos.x()/picSize;
    x=pos.y()/picSize;
    QPoint value;
    if(x>8||y>1)
        return;

    bool change=0;
    if(pushed){


        if(y==0){

            if(x>4){



                change=1;
                value=QPoint((9-x),push.y());



            }
            else{
                 qDebug()<<"qq";
                 baseClear();
                QTransform tpo;
                itemAt(pos,tpo)->setVisible(false);

                value=push;
                change=1;


            }
        }
        else{  \


            change=1;
            value=QPoint((13-x),push.y());

        }

        pushed=0;
        qDebug()<<value<<push;
    }

    else{
        if(y==0){

            if(x<5){
                baseClear();
                QTransform tpo;
                itemAt(pos,tpo)->setVisible(false);
                change=1;
                if(x==0)
                    value=QPoint(x,0);
                else
                    value=QPoint(0,x);

            }




        }
        if(change){
        push=value;



        }
        pushed=1;


        }


    QPoint f(0,0);
    QPoint val=f;

    if(change){
    val=value;

    }
    if(f==value&&change){
        clearAll();
    //
    }
    int size =choosedCards.size();
    for(int i=0;i<size;i++){
        if(choosedCards[i]==val)
            t=1;}
    if(!t&&!pushed){
    emit choosen(val);
    emit ckickedOnScene();
    }
}

void SmallCardScene::removeCard(QPoint P, bool SP){
    double x,y,t=0;

    x=(P.y()+1/2)*picSize;
    y=(P.x()+1/2)*picSize;

    int size =choosedCards.size();
    for(int i=0;i<size;i++){
        if(choosedCards[i]==P)
            t=1;}

    choosedCards.push_back(P);

    }

