#ifndef MODELINTERFACE_H
#define MODELINTERFACE_H

#include <QString>

namespace TicTacToe
{
   const int MAX_R = 3;
   const int MAX_C = 3;

   enum ITEM_VALUE
   {
     VAL_X = 0,
     VAL_O = 1,
     VAL_MAX = 2
   };

    class ModelInterface
    {
        public:

            virtual ~ModelInterface(){}

            virtual void InitBoard() = 0;
            virtual void SetValue(int r, int c, enum ITEM_VALUE val) = 0;
            virtual enum ITEM_VALUE GetValue(int r, int c) const = 0;
            virtual bool SaveBoard() = 0;
            virtual bool LoadBoard() = 0;

            virtual void SaveXUserName(QString name) = 0;
            virtual void SaveOUserName(QString name) = 0;
            virtual QString GetXUserName() const = 0;
            virtual QString GetOUserName() const = 0;

    };
}

#endif // MODELINTERFACE_H
