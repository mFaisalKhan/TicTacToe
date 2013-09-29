#ifndef GAMEVIEWINTERFACE_H
#define GAMEVIEWINTERFACE_H

#include "ModelInterface.h"
#include <QObject>

namespace TicTacToe
{
    class GameViewInterface: public QObject
    {
        Q_OBJECT
        public:
            virtual ~GameViewInterface() {}
            virtual void Initialize(void) = 0;
            virtual void Redraw(void) const = 0;
            virtual void ShowWinnerName (QString Name) const = 0;
            virtual void DrawWinnerLine(int r, int c) const = 0;
            virtual void SetBoardValue(int r, int c,ITEM_VALUE value) = 0;

        private slots:
            virtual void handle(void) = 0;

        signals:
            void BoardClicked(int r, int col);
            void User1Changed();
            void User2Changed();
            void SaveGameClicked();
            void LoadGameClicked();
    };
}

#endif // GAMEVIEWINTERFACE_H
