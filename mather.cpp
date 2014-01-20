#include "mather.h"

Mather::Mather()
{

totalCards=52;
r=new Referie;

}
void Mather::refresh(QVector<QPoint> &you,QVector<QPoint> &table
                         ,QVector<QPoint> &emnot,QVector<QPoint>&emyes
                         ,QVector<QPoint> & numb){
    yourCards=you;
    tableCards=table;
    enemiesNotCards=emnot;
    enemiesCards=emyes;


    chanseTie=0;//пїЅпїЅпїЅпїЅпїЅ
    chanseWin=0;
    chanseLoose=0;

     oppUnknCards.clear();
     numbPlayers=0;

     numbPlayers=numb.first().x();
    refreshUnknownCards();
     makeoppUnknCards();
}

float Mather::sumChanse(float ch,float N){
    if(N<0)
        return 0;
    float y=1-ch;
    float x = 1-pow(y,N);//-N*ch*ch/p;
    return x;
}


void  Mather::makeYourChanseOneCard(){
    int b=0;
    int p=0;
    int tie=0;
    QVector<QPoint> you;
        for(int j=0;j< unknownCards.size();j++){//my
           QVector<QPoint> im =tableCards+yourCards;
            im.push_back(unknownCards[j]);
            if(enemiesCards.size()<numbPlayers*2.0){
            for(int i=0;i< oppUnknCards.size();i++){//ypur


            for(int k=i+1;k<oppUnknCards.size();k++){
            if(unknownCards[j]!=oppUnknCards[i]&&unknownCards[j]!=oppUnknCards[k]
                    ){
                 you=enemiesCards+tableCards;
                you.push_back(oppUnknCards[i]);
                you.push_back(oppUnknCards[k]);
                you.push_back(unknownCards[j]);
                int ref=r->refer(im,you);
                if (ref==2)
                    b++;
                if(ref==1)
                    tie++;
                if(ref==0){
                    p++;
                    //qDebug()<<oppUnknCards[i]<<oppUnknCards[k]<<unknownCards[j];
                }
                you.clear();
            }
            }}
        }
            else{
                QVector <QPoint> im=yourCards+tableCards;
                QVector <QPoint> your=enemiesCards+tableCards;
                int ref =r->refer(im,your);
                if(ref==0){
                    p++;
                    //qDebug()<<im<<your;
                }
                if(ref==1)
                    tie++;
                if(ref==2)
                    b++;

            }

        }
    float bb=b;
    float tt=tie;
    float pp=p;
    float s=bb+tt+pp;
    bb/=s;
    tt/=s;
    pp/=s;
    s*=2.0;
    pp=sumChanse(pp,numbPlayers);
    tt=sumChanse(tt,numbPlayers);
    chanseWin+=bb;
    chanseTie+=tt;
    chanseLoose+=pp;
}

void Mather::makeYourChanseTwoCard(){
    int b=0;
    int p=0;
    int tie=0;
    QVector<QPoint> you;
    for(int q=0;q<unknownCards.size();q++){
        for(int j=q+1;j< unknownCards.size();j++){//my
           QVector<QPoint> im =tableCards+yourCards;
            im.push_back(unknownCards[j]);
            im.push_back(unknownCards[q]);
            if(enemiesCards.size()<numbPlayers*2.0){
            for(int i=j-1;i< oppUnknCards.size();i++){//ypur
            for(int k=i+1;k<oppUnknCards.size();k++){
            if(unknownCards[j]!=oppUnknCards[i]&&unknownCards[j]!=oppUnknCards[k]&&
                   unknownCards[q]!=oppUnknCards[i]&&unknownCards[q]!=oppUnknCards[k] ){
                 you=enemiesCards+tableCards;
                you.push_back(oppUnknCards[i]);
                you.push_back(oppUnknCards[k]);
                you.push_back(unknownCards[j]);
                you.push_back(unknownCards[q]);
                int ref=r->refer(im,you);
                if (ref==2)
                    b++;
                if(ref==1)
                    tie++;
                if(ref==0){
                    p++;
                }
                you.clear();
            }
            }}
            }
            else{
                QVector <QPoint> im=yourCards+tableCards;
                QVector <QPoint> your=enemiesCards+tableCards;
                int ref =r->refer(im,your);
                if(ref==0){
                    p++;
                    //qDebug()<<im<<your;
                }
                if(ref==1)
                    tie++;
                if(ref==2)
                    b++;

            }

        }
        }
    float bb=b;
    float tt=tie;
    float pp=p;
    float s=bb+tt+pp;
    bb/=s;
    tt/=s;
    pp/=s;
    s*=2.0;
    pp=sumChanse(pp,numbPlayers);
    tt=sumChanse(tt,numbPlayers);
    chanseWin+=bb;
    chanseTie+=tt;
    chanseLoose+=pp;
}
void Mather::makeYourChanseThreeCard(){
    int b=0;
    int p=0;
    int tie=0;
    QVector<QPoint> you;
     QVector<QPoint> im ;
    for(int l=0;l<unknownCards.size();l++){
    for(int q=l+1;q<unknownCards.size();q++){
        for(int j=q+1;j< unknownCards.size();j++){//my
             im =tableCards+yourCards;
            im.push_back(unknownCards[j]);
            im.push_back(unknownCards[q]);
            im.push_back(unknownCards[l]);
            if(enemiesCards.size()<numbPlayers*2.0){
            for(int i=j-2;i< oppUnknCards.size();i++){//ypur
            for(int k=i+1;k<oppUnknCards.size();k++){
            if(unknownCards[j]!=oppUnknCards[i]&&unknownCards[j]!=oppUnknCards[k]&&
                   unknownCards[q]!=oppUnknCards[i]&&unknownCards[q]!=oppUnknCards[k]&&
                    unknownCards[l]!=oppUnknCards[i]&&unknownCards[l]!=oppUnknCards[k]){
                 you=enemiesCards+tableCards;
                you.push_back(oppUnknCards[i]);
                you.push_back(oppUnknCards[k]);
                you.push_back(unknownCards[j]);
                you.push_back(unknownCards[q]);
                you.push_back(unknownCards[l]);
                int ref=r->baseRefer(im,you);
                if (ref==2)
                    b++;
                if(ref==1)
                    tie++;
                if(ref==0){
                    p++;
                }
                you.clear();
            }

            }}
        im.clear();
            }
            else{
                QVector <QPoint> im=yourCards+tableCards;
                QVector <QPoint> your=enemiesCards+tableCards;
                int ref =r->baseRefer(im,your);
                if(ref==0){
                    p++;
                    //qDebug()<<im<<your;
                }
                if(ref==1)
                    tie++;
                if(ref==2)
                    b++;

            }

        }}
        }
    float bb=b;
    float tt=tie;
    float pp=p;
    float s=bb+tt+pp;
    s*=3.0;
    bb/=s;
    tt/=s;
    pp/=s;

    pp=sumChanse(pp,numbPlayers);
    tt=sumChanse(tt,numbPlayers);
    chanseWin+=bb;
    chanseTie+=tt;
    chanseLoose+=pp;

}

void Mather:: makeoppUnknCards(){
    oppUnknCards.clear();
    int sz=enemiesNotCards.size();
    totalCards=unknownCards.size();

    for (int i=0;i<totalCards;i++){
        int t=0;
        int p=0;
        for(int j=0;j<sz;j++){
            if(unknownCards[i]==enemiesNotCards[j]||
                    (!enemiesNotCards[j].x()&&unknownCards[i].y()==enemiesNotCards[j].y()
                     )||(
                        !enemiesNotCards[j].y()&&unknownCards[i].x()==enemiesNotCards[j].x()
                        ))
                t++;
        }
        for(int k=0;k<yourCards.size();k++){
            if(unknownCards[i]==yourCards[k])
                p++;
        }

        if(!t&&!p){
            oppUnknCards.push_back(unknownCards[i]);
        }

    }
}


void Mather::makeoppTwoCard(){
    totalCards=unknownCards.size();
    int sz=oppUnknCards.size();
   int b=0;
    int p=0;
    int tie=0;
    if(enemiesCards.size()<numbPlayers*2.0){
    for (int k=0;k<sz;k++){
    for (int i=k+1;i<sz;i++){
         if(i!=k){


        QVector <QPoint> im=yourCards+tableCards;
        QVector <QPoint> en=enemiesCards;
        en.push_back(oppUnknCards[i]);
        en.push_back(oppUnknCards[k]);
        QVector <QPoint> your=tableCards+en;
        int ref =r->refer(im,your);
        if(ref==0){
            p++;
            //qDebug()<<im<<your;
        }
        if(ref==1)
            tie++;
        if(ref==2)
            b++;
         }}}
    }
    else{
        QVector <QPoint> im=yourCards+tableCards;
        QVector <QPoint> your=enemiesCards+tableCards;
        int ref =r->refer(im,your);
        if(ref==0){
            p=1;
            //qDebug()<<im<<your;
        }
        if(ref==1)
            tie=1;
        if(ref==2)
            b=1;

    }
//qDebug()<<b<<p;
    float bb=b;
    float tt=tie;
    float pp=p;
    float s=bb+tt+pp;
    bb/=s;
    tt/=s;
    pp/=s;
    pp=sumChanse(pp,numbPlayers);
    tt=sumChanse(tt,numbPlayers);

    chanseWin+=bb;
    chanseTie+=tt;
    chanseLoose+=pp;
}


void Mather::refreshUnknownCards(){
    unknownCards.clear();

    QVector<QPoint> known=yourCards+tableCards+enemiesCards;

    for(int i=1;i<5;i++){
        for(int j=1;j<14;j++){
            QPoint var(j,i);
            int t=0;
            for(int k=0;k<known.size();k++)
            {
                if(var==known[k])
                    t=1;
            }
            if(!t)
                unknownCards.push_back(var);
        }
    }

}





void Mather::makeAWin(){
    refreshUnknownCards();
     makeoppUnknCards();
    if (yourCards.size()==2&&(tableCards.size()!=2&&tableCards.size()!=1)){
    makeoppTwoCard();
    if(tableCards.size()!=5&&tableCards.size()!=0){
    makeYourChanseOneCard();
    QPoint y,o;
    QVector<QPoint> my=yourCards+tableCards;
    QVector<QPoint> opp=enemiesCards+tableCards;
    my=r->sort(my);
    opp=r->sort(opp);
    qDebug()<<r->detCombine(my,y)<<r->detCombine(opp,o);
    qDebug()<<y<<o;
    qDebug()<<r->refer(my,opp);

    }



}}


