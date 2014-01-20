#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gcardscene.h"
#include "playerscene.h"
#include "mather.h"
#include "smallcardscene.h"
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Mather *math;
    PlayerScene * player;
    PlayerScene * table;
    PlayerScene * eneNot;
    PlayerScene * eneYes;
    PlayerScene * numb;
    //SmallCardScene * scene;
    SmallCardScene * scene;
    void rdraw();
    void disactiveLastScene(PlayerScene *);
    ~MainWindow();
  protected:
void testPlayerScenes();
void changeEvent(QEvent *);
 void mousePressEvent( QMouseEvent *);
 void resizeEvent(QResizeEvent *);

signals:
 void sendToBankLabel(QString );
 void sendToValBankLabel(QString );
 void sendToChanseLabel(QString);

 public slots:

 void bankChanged(QString );
 void sceneClicked();
 void butClicked();
 void testClear();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
