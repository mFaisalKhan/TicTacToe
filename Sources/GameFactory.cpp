#include <QtCore/QString>
#include <QtTest/QtTest>
#include "ModelInterface.h"
#include "GameModel.h"
#include "GameView.h"
#include "GameViewInterface.h"
#include "MainWindow.h"
#include "Controller.h"

using namespace TicTacToe;

int main(int argc, char *argv[])
{
   QApplication app(argc,argv);

   MainWindow mywindow;
   GameViewInterface *viewRef = new GameView(mywindow);
   ModelInterface *modelRef = new GameModel();
   Controller controller(*viewRef, *modelRef);
   mywindow.show();

   int retCode = app.exec();
   delete viewRef;
   delete modelRef;
   return retCode;
}

