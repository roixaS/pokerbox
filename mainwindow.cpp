#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //scene=new SmallCardScene;
    scene=new SmallCardScene;
    math=new Mather;
    player=new PlayerScene;
    table=new PlayerScene;
    eneNot=new PlayerScene;
    eneYes=new PlayerScene;
    numb=new PlayerScene;
    rdraw();
    player->draw(" your cards",2);
    table->draw(" table cards",5);
    eneYes->draw(" opponents cards",5);
    eneNot->draw(" not opponents cards",5);
    numb->draw(" playing peoples",1);
    numb->special=1;
    numb->active=1;
    player->real=1;
    table->real=1;

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_5->setScene(player);
    ui->graphicsView_4->setScene(table);
    ui->graphicsView_3->setScene(eneNot);
    ui->graphicsView_2->setScene(eneYes);
    ui->graphicsView_6->setScene(numb);
    //ui->horizontalLayout


    QObject::connect(scene, SIGNAL(	 choosen(QPoint ) ),
           player, SLOT(setcard(QPoint )));
    QObject::connect(player, SIGNAL(cardSetted(QPoint,bool) ),
                     scene, SLOT(removeCard(QPoint,bool)));

    QObject::connect(scene, SIGNAL(	 choosen(QPoint ) ),
           table, SLOT(setcard(QPoint )));
    QObject::connect(table, SIGNAL(cardSetted(QPoint,bool) ),
                     scene, SLOT(removeCard(QPoint,bool)));

    QObject::connect(scene, SIGNAL(	 choosen(QPoint ) ),
           eneNot, SLOT(setcard(QPoint )));
    QObject::connect(eneNot, SIGNAL(cardSetted(QPoint,bool) ),
                     scene, SLOT(removeCard(QPoint,bool)));

    QObject::connect(scene, SIGNAL(	 choosen(QPoint ) ),
           eneYes, SLOT(setcard(QPoint )));
    QObject::connect(eneYes, SIGNAL(cardSetted(QPoint,bool) ),
                     scene, SLOT(removeCard(QPoint,bool)));

    QObject::connect(scene, SIGNAL(	 choosen(QPoint ) ),
           numb, SLOT(setcard(QPoint )));
    QObject::connect(numb, SIGNAL(cardSetted(QPoint,bool) ),
                     scene, SLOT(removeCard(QPoint,bool)));
    QObject::connect(player, SIGNAL(sendNext()) ,
                     table, SLOT(recive()));
    QObject::connect(table, SIGNAL(sendNext()) ,
                             eneNot, SLOT(recive()));
    QObject::connect(eneNot, SIGNAL(sendNext()) ,
                                     eneYes, SLOT(recive()));
    QObject::connect(numb, SIGNAL(sendNext()) ,
                                             player, SLOT(recive()));
    QObject::connect(this, SIGNAL(sendToBankLabel(QString)	  ),
           ui->lineEdit_3, SLOT(setText(QString)));
    QObject::connect(this, SIGNAL(sendToChanseLabel(QString))	  ,
           ui->lineEdit, SLOT(setText(QString)));
    QObject::connect(this, SIGNAL(sendToValBankLabel(QString)	  ),
           ui->lineEdit_2, SLOT(setText(QString)));
    QObject::connect(ui->lineEdit_2, SIGNAL(textChanged(QString))	  ,
           this, SLOT(bankChanged(QString )));
    QObject::connect(scene, SIGNAL(ckickedOnScene())	  ,
           this, SLOT(sceneClicked()));
    QObject::connect(ui->button, SIGNAL(clicked())	  ,
               this, SLOT(butClicked()));
    QObject::connect(player, SIGNAL(sendToActive())	  ,
               this, SLOT(testClear()));
    QObject::connect(table, SIGNAL(sendToActive())	  ,
               this, SLOT(testClear()));
    QObject::connect(eneNot, SIGNAL(sendToActive())	  ,
               this, SLOT(testClear()));
    QObject::connect(eneYes, SIGNAL(sendToActive())	  ,
               this, SLOT(testClear()));
    QObject::connect(numb, SIGNAL(sendToActive())	  ,
               this, SLOT(testClear()));


}
void MainWindow::testClear(){
    testPlayerScenes();
}


void MainWindow::butClicked(){
   {
        math->refresh(player->cardsValues,table->cardsValues,
                    eneNot->cardsValues,eneYes->cardsValues,numb->cardsValues);
        QString P,q,t;
        math->makeAWin();
         if(table->cardsValues.size()==3)
        math->makeYourChanseTwoCard();
         if(table->cardsValues.size()==0){
        math->makeYourChanseThreeCard();
        float c=math->chanseWin+math->chanseLoose;
        float p=math->chanseWin;
        t=t.setNum(p*(100.0)/c);
        P=P.setNum(100.0);
        emit sendToBankLabel(t);
        emit sendToValBankLabel(P);
         }
        q=P.setNum((math->chanseWin+math->chanseTie)/(math->chanseWin+math->chanseTie+math->chanseLoose)*100.0);
        emit sendToChanseLabel(q);
    }
}
void MainWindow::bankChanged(QString  x){

    float buff=x.toFloat();


    buff=buff*math->chanseWin/(math->chanseWin+math->chanseLoose);
    QString lk=x.setNum(buff);
    emit sendToBankLabel(lk);
}
void MainWindow::mousePressEvent (QMouseEvent *){



}

void MainWindow::disactiveLastScene(PlayerScene * x){
    if(x->last&&x->active){
        x->disActive();
        //qDebug()<<"q";
    }
    if(!x->last&&x->active)
        x->recive();
}
void MainWindow::testPlayerScenes(){
    disactiveLastScene(table);
    disactiveLastScene(player);
    disactiveLastScene(eneNot);
    disactiveLastScene(eneYes);
    disactiveLastScene(numb);
   }
void MainWindow::changeEvent(QEvent *){


}
void MainWindow::sceneClicked(){

    math->refresh(player->cardsValues,table->cardsValues,
                eneNot->cardsValues,eneYes->cardsValues,numb->cardsValues);
    math->makeAWin();
    QString P,q,t;
    q=P.setNum((math->chanseWin+math->chanseTie)/(math->chanseWin+math->chanseTie+math->chanseLoose)*100.0);
    float p=math->chanseWin;
    float c=math->chanseWin+math->chanseLoose;
    t=t.setNum(p*(100.0)/c);
    P=P.setNum(100.0);
    emit sendToChanseLabel(q);
    emit sendToBankLabel(t);
    emit sendToValBankLabel(P);

}

void MainWindow::rdraw(){
    QSize g=this->size();
    float w,h;
    w=g.width()/2.1;
    h=g.height()/7.1;
    player->wid=w;
    player->high=h;
    table->wid=w;
    table->high=h;
    eneNot->wid=w;
    eneNot->high=h;
    eneYes->wid=w;
    eneYes->high=h;
    numb->wid=w;
    numb->high=h;
    //float h=player->high/1.8;//15.1;
    //player->cardSize=h;
    player->redraw();
   table->redraw();
    eneNot->redraw();
    eneYes->redraw();
    numb->redraw();
    //scene->redraww(w,h);
    w=g.width()/2.6;
    h=g.height();

     //ui->graphicsView->setSizeIncrement(w,h);
    //h=scene->sceneRect().bottomRight().y();
    //qDebug()<<h<<w;
    //scene->wight=w;
    //scene->hight=h;
    scene->redraww(w,h);
}

 void MainWindow::resizeEvent(QResizeEvent *ev){
     rdraw();
     //table->cardSize=h;
     //scene->picSize=h;
     //ui->horizontalLayout->s;
     //scene->picSize=this->size().width()/10;
 }

MainWindow::~MainWindow()
{
    delete ui;
}
