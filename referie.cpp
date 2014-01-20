#include "referie.h"

Referie::Referie()
{
}

int Referie::detCombine(QVector<QPoint> &xx,QPoint& c){

    QPoint y(0,0);
    QPoint buff;
    buff=isRoyaleFlash(xx);
    if(buff!=y){
        c=buff;
        return 85;
    }
    buff=isKare(xx);
    if(buff!=y){
        c=buff;
        return 75;
    }
    buff=isFullHouse(xx);
    if(buff!=y){
        c=buff;
        return 65;
    }
    buff=isFlash(xx);
    if(buff!=y){
        c=buff;
        return 55;

    }
    buff=isStrate(xx);
    if(buff!=y){
        c=buff;
        return 45;

    }
    buff=isTrip(xx);
    if(buff!=y){
        c=buff;
        return 35;

    }
    buff=isTwoPares(xx);
    if(buff!=y){
        c=buff;
        return 25;

    }
    buff=isPare(xx);
    if(buff!=y){
        c=buff;
        return 15;

    }
    buff=isKicker(xx);
    if(buff!=y){
        c=buff;
        return isKicker(xx).x();

    }
    }

int Referie::baseRefer(QVector<QPoint> my,QVector<QPoint> you){
    QPoint f(0,0);
    QPoint myf=isFlash(my);
    QPoint mys=isStrate(my);
    QPoint yof=isFlash(you);
    QPoint yos=isStrate(you);
    if(myf!=f&&yof==f)
        return 2;
    if(myf==f&&yof!=f)
        return 0;
    if(myf==yof&&myf!=f)
        return 1;
    if(myf.x()>yof.x())
        return 2;
    if (myf.x()<yof.x())
        return 0;
    if(mys!=f&&yos==f)
        return 2;
    if(mys==f&&yos!=f)
        return 0;
    if(mys==yos&&mys!=f)
        return 1;
    if(mys.x()>yos.x())
        return 2;
    if (mys.x()<yos.x())
        return 0;
    int ii=my.size();
    int jj=you.size();
    if(jj>ii)
        jj=ii;
    else ii=jj;

    for(int i=ii-1;i>-1;i--){

        if (my[i].x()>you[i].x())
            return 2;

        if (my[i].x()<you[i].x())
            return 0;}
    return 1;


}


int Referie::referKicker(QVector<QPoint> &my,QVector<QPoint> &you,QPoint mb,QPoint yb,int sim){
    int sz;
    if(my.size()>you.size())
        sz=you.size();
    else
        sz=my.size();
    int u=0;
    QVector<QPoint> newmy;

    QVector<QPoint> newyou;
    for(int i=0;i<my.size();i++){
        bool impare=my[i].x()==mb.x()||my[i].x()==mb.y();
                if(!impare)
            newmy.push_back(my[i]);
     }

     for(int i=0;i<you.size();i++){
         bool youpare=you[i].x()==yb.x()||you[i].x()==yb.y();
           if(!youpare)
             newyou.push_back(you[i]);
    }

    newmy=sort(newmy);
    newyou=sort(newyou);

    if(newmy.size()>newyou.size())
        sz=newyou.size();
    else
        sz=newmy.size();

       for(int i=sz-1;i>sz-6+sim;i--){
        if(newmy[i].x()<newyou[i].x())
            return 0;
        if(newmy[i].x()>newyou[i].x())
            return 2;
    }
    return 1;
}


int Referie::refer(QVector<QPoint> im,QVector<QPoint> you){
    QPoint inBuff;
    QPoint youBuff;
    im=sort(im);
    you=sort(you);

    int my=detCombine(im, inBuff );
    int your=detCombine(you, youBuff);
    QPoint ime=inBuff;
    QPoint yme=youBuff;
    //qDebug()<<my<<your<<im<<you;
    if(my>your)
        return 2;

    if(my<your){

        return 0;

    }
    if(my==your){
        if (my==85){//royal
            int i=ime.x();
            int y=yme.x();
            if(i>y)
                return 2;
            if(i<y)

                return 0;
            else
                return 1;
        }

        if (my==75){//kare
            if(ime.x()<yme.x())
                return 0;
            if(ime.x()>yme.x())

            return 2;

            if(ime.x()==yme.x()){
                return referKicker(im,you,ime,yme,4);

            }

        }
        if (my==65){//fh
            if(inBuff.x()==youBuff.x()){
                if(inBuff.y()<youBuff.y())
                    return 0;
                if (inBuff.y()==youBuff.y())
                    return 1;
                else return 2;
            }
            if(inBuff.x()<youBuff.x())
                return 0;
            else return 2;
        }
        if (my==55){//flash
            if(inBuff.x()<youBuff.x())
                return 0;
                if (inBuff.x()==youBuff.x())
                    return 1;
                if(inBuff.x()>youBuff.x())
                    return 2;
        }
        if (my==45){//strate
            if(inBuff.x()<youBuff.x())
                return 0;
                if (inBuff.x()==youBuff.x())
                   return 1;
                if (inBuff.x()>youBuff.x())
                    return 2;

        }
        if (my==35){//triple
            if(inBuff.x()<youBuff.x())
                return 0;
                if (inBuff.x()==youBuff.x()){
                    return referKicker(im,you,inBuff,youBuff,3);

                }
                else return 2;
        }

        if (my==25){//two pares
            if(inBuff.x()<youBuff.x())
                return 0;
            if (inBuff.x()>youBuff.x())
                return 2;
            if (inBuff.x()==youBuff.x()){
                if(inBuff.y()<youBuff.y())
                    return 0;
                if (inBuff.y()==youBuff.y()){

                   return referKicker(im,you,inBuff,youBuff,2);


                }}
                    return 2;


        }
        if (my==15){//pare
            if(inBuff.x()<youBuff.x())
                return 0;
            if (inBuff.x()==youBuff.x()){
               return referKicker(im,you,inBuff,youBuff,2);
        }
            return 2;

        }
        if(my<15){
            return referKicker(im,you,inBuff,youBuff,0);
                }
    }
}


QPoint Referie::isKicker(QVector<QPoint> &xx){

    QPoint x=xx.last();
    return x;
}

QVector<QPoint> Referie::sort(QVector<QPoint> &xx){
    int sz=xx.size();
    QVector<QPoint> xxx=xx;
    int swap;
    for(int j=0;j<sz-1;j++){;
        for(int i=0;i<sz-j-1;i++){
            if(xxx[i].x()>xxx[i+1].x()){
                swap=xxx[i].x();
                xxx[i].setX(xxx[i+1].x());
                xxx[i+1].setX(swap);
                swap=xxx[i].y();
                xxx[i].setY(xxx[i+1].y());
                xxx[i+1].setY(swap);
      }}}
   return xxx;
}

QPoint Referie::isPare(QVector<QPoint> &xx){
    int lk=xx.size();
    for(int i=13;i>0;i--){
        int p=0;
        for(int j=0;j<lk;j++){

            if(xx[j].x()==i){
               p++;

            }

        }
        if(p==2){
            int y;
            if(i!=(lk-1))
                y=xx.last().x();
            else
                y=xx[lk-2].x();
            QPoint gh(i,0);
            return gh;
        }
    }
    QPoint f(0,0);
    return f;
}

QPoint Referie::isTwoPares(QVector<QPoint> &xx){
    int lk=xx.size();
    int k=0;
    int q=0;
    for(int i=13;i>0;i--){
        int p=0;
        for(int j=0;j<lk;j++){
            if(xx[j].x()==i)
               p++;}
        if(p==2){
            k=i;
            break;
        }
      }
    for(int i=13;i>0;i--){
        int p=0;
        for(int j=0;j<lk;j++){
            if(xx[j].x()==i)
               p++;

        }
        if(p==2&&k>i){
            q=i;
            break;
        }
      }
    QPoint gh(k,q);
    if(k&&q)
        return gh;
    QPoint f(0,0);
    return f;
}

QPoint Referie::isTrip(QVector<QPoint> &xx){
    int lk=xx.size();
    for(int i=13;i>0;i--){
        int p=0;
        for(int j=0;j<lk;j++){
            if(xx[j].x()==i)
               p++;}
        if(p==3){
            QPoint gh(i,0);
            return gh;
        }
    }
    QPoint f(0,0);
    return f;
}


QPoint Referie::isStrate(QVector<QPoint> xx ){//!!!


   if(xx.last().x()==13){
        QPoint p(0,xx.last().y());
        xx.push_front(p);

     }


    int sz=xx.size();


    int str=sz-5;
    if (str>=0){
    for(int i=0;i<sz-4;i++){
        int t=0;
        int p=0;
        for(int j=sz-2-i;j>-1;j--){//+str
            bool strEl=(xx[j].x()==(xx[j+1].x()-1));
            bool pareEl=xx[j].x()==xx[j+1].x();
            if(!strEl&&!pareEl||t==4)
                break;
            if(strEl)//-
                t++;
            if(pareEl)
                p++;
           }
        if(t==4){
            QPoint pp=xx[sz-1-i];
             return pp;
        }
    }}
    QPoint f(0,0);
    return f;
}

QPoint Referie::isFlash(QVector<QPoint> &xx){
    int sz=xx.size();
    for(int i=1;i<5;i++){
        int t=0;
        int p=0;
        for(int j=0;j<sz;j++){

            if (xx[j].y()==i){
                t++;}

        }
       if(t>=5){
            for(int k=0;k<sz;k++){

                if(xx[k].y()==i&&xx[k].x()>p){
                    p=xx[k].x();


            }}
            QPoint gh(p,i);

       return gh;
    }

    }
    QPoint f(0,0);
    return f;
}

QPoint Referie::isFullHouse(QVector<QPoint> &xx){
    int k=0;
    int q=0;
    int lk=xx.size();
    for(int i=1;i<14;i++){
            int p=0;
            for(int j=0;j<lk;j++){
                if(xx[j].x()==i)
                   p++;}
            if(p==3){
                k=i;
            }
        }
    for(int i=1;i<14;i++){
        int p=0;
        for(int j=0;j<lk;j++){
            if(xx[j].x()==i)
               p++;}
        if(p==2&&k!=i){
            q=i;
        }
      }
    if(k&&q){
        QPoint gh(k,q);
        return gh;
    }
    QPoint f(0,0);
    return f;
}

QPoint Referie::isKare(QVector<QPoint> &xx){
    int sz=xx.size();
    for(int i=13;i>0;i--){
        int t=0;
        for(int j=0;j<sz;j++){
            if (xx[j].x()==i)
                t++;
       }
        if(t==4){
        QPoint gh(i,0);
        return gh;
    }}
    QPoint f(0,0);
    return f;
}



QPoint Referie::isRoyaleFlash(QVector<QPoint> &xxx){
    QPoint f(0,0);
    QVector<QPoint> xx=xxx;
    if(xx.last().x()==13){
         QPoint p(0,xx.last().y());
         xx.push_front(p);

      }

     int sz=xx.size();
     int str=sz-5;
     if (str>=0){

         for(int i=0;i<sz-4;i++){
                 int t=0;
                 int p=0;
                 int k=0;
                 for(int j=sz-2-i;j>-1;j--){//+str
                     bool strEl=(xx[j].x()==(xx[j+1].x()-1));
                     bool pareEl=xx[j].x()==xx[j+1].x();
                     bool fla=(xx[sz-1-i].y()==(xx[j].y()));
                     bool ace=xx[j+1].x()==13;
                     bool exect=ace&&!pareEl&&!strEl;
                     bool empty=((!strEl)&&!pareEl&&!fla);
                     if(empty||(((t==4)||(p==4))&&!pareEl)||exect)
                         break;
                     if(strEl)//-
                         t++;

                     if(fla)
                         p++;


                    }

                 if((t==(4))&&(p==(4))){
                     QPoint pp=xx[sz-1-i];
                      return pp;
                 }
             }


     }
    return f;
}

