#include "Controller.h"
#include "ModelInterface.h"
#include <QDebug>

namespace TicTacToe
{
    Controller::Controller(GameViewInterface &view, ModelInterface &model)
        : State(STATE_INIT)
        , View(view)
        , Model(model)
        , ValuesRemaining(9)
    {
        connect(&View,SIGNAL(BoardClicked(int, int)), this, SLOT(HandleBoardClicked(int,int)));
        connect(&View,SIGNAL(SaveGameClicked()), this, SLOT(HandleSaveGameClicked()));
        connect(&View,SIGNAL(LoadGameClicked()), this, SLOT(HandleLoadGameClicked()));

        Model.SaveXUserName("Default X");
        Model.SaveOUserName("Default O");
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void Controller::HandleBoardClicked(int r, int c)
    {
        qDebug("r,c %d %d", r,c);
        Run(r,c);
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void Controller::HandleSaveGameClicked()
    {
        Model.SaveBoard();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void Controller::HandleLoadGameClicked()
    {
        Model.LoadBoard();

        View.Redraw();
         for(int i=0; i<3; i++)
            for(int j=0;j<3;j++)
                View.SetBoardValue(i,j,Model.GetValue(i,j));
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void Controller::ProcessState(int r, int c)
    {
        if(Model.GetValue(r,c) == VAL_MAX)
        {
            QString userName;
            ValuesRemaining--;

            if(State == STATE_TURN_X)
            {
                State=STATE_TURN_O;
                Model.SetValue(r,c,VAL_X);
                View.SetBoardValue(r,c,VAL_X);
                userName=Model.GetXUserName();
            }
            else
            if(State == STATE_TURN_O)
            {
                State=STATE_TURN_X;
                Model.SetValue(r,c,VAL_O);
                View.SetBoardValue(r,c,VAL_O);
                userName = Model.GetOUserName();
            }


            ITEM_VALUE winner = checkWinner();
            qDebug("winner %d",winner);
            if(winner!= VAL_MAX)
            {
                State = STATE_INIT;
                View.ShowWinnerName(userName);
                View.DrawWinnerLine(r,c);
            }
            else
            if(ValuesRemaining==0)
            {
                State=STATE_DRAW;
                Run(r,c);
            }

        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void Controller::Run(int r, int c)
    {
        qDebug("State = %d", State);

        switch(State)
        {
        case STATE_INIT:
            View.Initialize();
            Model.InitBoard();
            State = STATE_TURN_X;
            ValuesRemaining=9;
            Run(r,c);
            break;
        case STATE_TURN_X:
        case STATE_TURN_O:
            ProcessState(r,c);
            break;
        case STATE_DRAW:
            State = STATE_INIT;
            View.ShowWinnerName("Board Draw");
            break;

        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    ITEM_VALUE Controller::checkWinner()
    {
        ITEM_VALUE val = VAL_MAX;


        if(( Model.GetValue(0,0) < VAL_MAX) && (Model.GetValue(0,0) == Model.GetValue(0,1)) && (Model.GetValue(0,0) == Model.GetValue(0,2))) val = Model.GetValue(0,0);
        else
        if(( Model.GetValue(1,0) < VAL_MAX) && (Model.GetValue(1,0) == Model.GetValue(1,1)) && (Model.GetValue(1,0) == Model.GetValue(1,2))) val = Model.GetValue(1,0);
        else
        if(( Model.GetValue(2,0) < VAL_MAX) && (Model.GetValue(2,0) == Model.GetValue(2,1)) && (Model.GetValue(2,0) == Model.GetValue(2,2))) val = Model.GetValue(2,0);
        else
        if(( Model.GetValue(0,0) < VAL_MAX) && (Model.GetValue(0,0) == Model.GetValue(1,0) ) && (Model.GetValue(0,0)== Model.GetValue(2,0))) val = Model.GetValue(0,0);
        else
        if(( Model.GetValue(0,1) < VAL_MAX) && (Model.GetValue(0,1) == Model.GetValue(1,1)) && (Model.GetValue(0,1) == Model.GetValue(2,1))) val = Model.GetValue(0,1);
        else
        if(( Model.GetValue(0,2) < VAL_MAX) && (Model.GetValue(0,2) == Model.GetValue(1,2)) && (Model.GetValue(0,2) == Model.GetValue(2,2))) val = Model.GetValue(0,2);
        else
        if(( Model.GetValue(0,0) < VAL_MAX) && (Model.GetValue(0,0) == Model.GetValue(1,1)) && (Model.GetValue(0,0) == Model.GetValue(2,2))) val = Model.GetValue(0,0);
        else
        if(( Model.GetValue(0,2) < VAL_MAX) && (Model.GetValue(0,2) == Model.GetValue(1,1)) && (Model.GetValue(0,2) == Model.GetValue(2,0))) val = Model.GetValue(0,2);

        return val;
    }


}
