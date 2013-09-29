#include "GameModel.h"
#include "ModelInterface.h"
#include <iostream>
#include <fstream>

namespace TicTacToe
{
    const QString BOARD_PERSISTENCE_LOCATION("./board.dat");
    GameModel::GameModel()
    {
    }

    GameModel::~GameModel()
    {

    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameModel::InitBoard()
    {
        for(int i=0; i<MAX_R; i++)
            for(int j=0; j<MAX_C;j++)
                Board[i][j] =VAL_MAX;
    }

   ///////////////////////////////////////////////////////////////////////////////////////////
    void GameModel::SetValue(int r, int c, ITEM_VALUE val)
    {
        if(r<MAX_R && c<MAX_C && val<VAL_MAX)
        {
            Board[r][c] = val;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    ITEM_VALUE GameModel::GetValue(int r, int c) const
    {
        if(r<MAX_R && c<MAX_C)
        {
           return Board[r][c];
        }
        else
            return VAL_MAX;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    bool GameModel::SaveBoard()
    {
        std::ofstream outStream;
        bool ret = false;

        outStream.open(BOARD_PERSISTENCE_LOCATION.toStdString().c_str(), std::ios::binary);
        if(outStream.is_open())
        {
            char *data = (char*)Board;
            outStream.write(data, sizeof(Board));

            int len = XUserName.length();
            outStream.write((char*) &len,sizeof(int));

            data = (char*) XUserName.toStdString().c_str();
            outStream.write(data, len);

            len = OUserName.length();
            outStream.write((char *) &len,sizeof(int));

            data = (char*) OUserName.toStdString().c_str();
            outStream.write(data, len);

            outStream.close();
            ret = true;
        }


        return ret;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    bool GameModel::LoadBoard()
    {
        std::ifstream inStream;
        bool ret = false;

        inStream.open(BOARD_PERSISTENCE_LOCATION.toStdString().c_str(), std::ios::binary);
        if(inStream.is_open())
        {
            // Board
            inStream.read((char*)Board, sizeof(Board));

            int len=0;
            inStream.read((char *) &len, sizeof(int));

            char userName[50];
            memset(userName,0,sizeof(userName));
            inStream.read(userName,len);
            XUserName = QString(userName);

            memset(userName,0,sizeof(userName));
            inStream.read((char *) &len, sizeof(int));
            inStream.read(userName,len);
            OUserName = QString(userName);

            inStream.close();
            ret = true;
        }

        return ret;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameModel::SaveXUserName(QString name)
    {
        XUserName = name;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameModel::SaveOUserName(QString name)
    {
        OUserName = name;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    QString GameModel::GetXUserName() const
    {
        return XUserName;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    QString GameModel::GetOUserName() const
    {
        return OUserName;
    }
}
