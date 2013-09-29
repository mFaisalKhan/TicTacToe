#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "GameViewInterface.h"
#include "MainWindow.h"
#include <QString>
#include <QPushButton>

namespace TicTacToe
{
    class GameView : public GameViewInterface
    {
        Q_OBJECT
        public:
           GameView(MainWindow &mainWindow);

           virtual ~GameView();
           void Initialize(void);
           void Redraw(void) const;
           void ShowWinnerName (QString Name) const;
           void DrawWinnerLine(int r, int c) const;
           void SetBoardValue(int r, int c,ITEM_VALUE value);
        signals:
           void BoardClicked(int r, int c);
           void SaveGameClicked();
           void LoadGameClicked();

        private slots:
           void handle(void);

        private:
           void SetupButtons(void);
        private:
           MainWindow &PtrMainWindow;
           QPushButton *ButtonLookup[3][3];
    };

}

#endif // GAMEVIEW_H
