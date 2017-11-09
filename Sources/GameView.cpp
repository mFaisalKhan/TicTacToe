#include "GameView.h"
#include "ui_MainWindow.h"
//made a change in this file

namespace TicTacToe
{

    GameView::GameView(MainWindow &mainWindow)
        :PtrMainWindow(mainWindow)
    {
        SetupButtons();
        Initialize();
    }

    GameView::~GameView()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::SetupButtons(void)
    {
        ButtonLookup[0][0] = PtrMainWindow.ui->pushButton00;
        ButtonLookup[0][1] = PtrMainWindow.ui->pushButton01;
        ButtonLookup[0][2] = PtrMainWindow.ui->pushButton02;

        ButtonLookup[1][0] = PtrMainWindow.ui->pushButton10;
        ButtonLookup[1][1] = PtrMainWindow.ui->pushButton11;
        ButtonLookup[1][2] = PtrMainWindow.ui->pushButton12;

        ButtonLookup[2][0] = PtrMainWindow.ui->pushButton20;
        ButtonLookup[2][1] = PtrMainWindow.ui->pushButton21;
        ButtonLookup[2][2] = PtrMainWindow.ui->pushButton22;

        for(int i=0;i<MAX_R;i++)
            for(int j=0;j<MAX_C;j++)
                connect(ButtonLookup[i][j] ,SIGNAL(clicked()), this, SLOT(handle()));
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::Initialize(void)
    {
        for(int i=0;i<MAX_R;i++)
            for(int j=0;j<MAX_C;j++)
                ButtonLookup[i][j]->setText("");

        PtrMainWindow.ui->Frame_Winner->hide();

        connect(PtrMainWindow.ui->actionSave_Game, SIGNAL(triggered(bool)), this, SIGNAL(SaveGameClicked()));
        connect(PtrMainWindow.ui->actionLoad_Game, SIGNAL(triggered(bool)), this, SIGNAL(LoadGameClicked()));
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::Redraw(void) const
    {
        PtrMainWindow.ui->Frame_Winner->hide();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::ShowWinnerName (QString Name) const
    {
         PtrMainWindow.ui->label->setText(Name);
         PtrMainWindow.ui->Frame_Winner->show();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::DrawWinnerLine(int r, int c) const
    {

    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::SetBoardValue(int r, int c,ITEM_VALUE value)
    {
        QString text;
        if(value == VAL_X) text = "X";
        else
        if(value == VAL_O) text = "O";

        if(r<MAX_R && c<MAX_C)
        {
            ButtonLookup[r][c]->setText(text);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////
    void GameView::handle(void)
    {
      QPushButton *button = static_cast<QPushButton *> (QObject::sender());
      if(button)
        {
           QString num = button->objectName().right(2);
          int row =  num.left(1).toInt();
          int col =  num.right(1).toInt();

          emit  BoardClicked(row, col);
      }
    }

}
