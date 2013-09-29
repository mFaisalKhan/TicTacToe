#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "GameViewInterface.h"

namespace TicTacToe
{
    class ModelInterface;
    class GameViewInterface;

    enum States
    {
        STATE_INIT,
        STATE_TURN_X,
        STATE_TURN_O,
        STATE_DRAW,
        STATE_WON
    };

    class Controller: public QObject
    {
        Q_OBJECT
        public:
            Controller(GameViewInterface &, ModelInterface &);
            ITEM_VALUE checkWinner();
        private slots:
            void HandleBoardClicked(int,int);
            void HandleSaveGameClicked();
            void HandleLoadGameClicked();

        private:
            void Run(int r, int c);
            void ProcessState(int r, int c);

            int State;
            GameViewInterface &View;
            ModelInterface &Model;
            int ValuesRemaining;
    };
}

#endif // CONTROLLER_H
