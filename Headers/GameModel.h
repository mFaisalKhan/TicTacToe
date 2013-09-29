#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QString>
#include "ModelInterface.h"

namespace TicTacToe
{
    class ModelInterface;

    class GameModel: public ModelInterface
    {
        public:
            GameModel();
            virtual ~GameModel();

            void InitBoard();
            void SetValue(int r, int c, ITEM_VALUE val);
            ITEM_VALUE GetValue(int r, int c) const;
            bool SaveBoard();
            bool LoadBoard();

            void SaveXUserName(QString name);
            void SaveOUserName(QString name);
            QString GetXUserName() const;
            QString GetOUserName() const;
        private:
            ITEM_VALUE Board[MAX_R][MAX_C];
            QString XUserName;
            QString OUserName;
    };
}

#endif // GAMEMODEL_H
