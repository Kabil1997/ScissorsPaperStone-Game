#pragma once
#include"clsRoundScreen.h"
#include"clsGameOverScreen.h"



class clsGamePlayScreen
{

    short HowManyRounds()
    {
        short GameRounds;
        cout << "How Many Rounds [1 to 10] : ";
        cin >> GameRounds;
        while (GameRounds <= 0 || GameRounds > 10)
        {
            cin >> GameRounds;
        }
        cout << endl << endl;
        return GameRounds;
    }


    short ReadPlayerChoice()
    {
        short PlayerChoice;
        cin >> PlayerChoice;
        while (PlayerChoice < 1 || PlayerChoice > 3)
        {
            cin >> PlayerChoice;
        }
        return PlayerChoice - 1;
    }

    void ShowGamePlayScreen()
    {
        short GameRounds = HowManyRounds();
        clsRound::Srand();
        clsRound Round(GameRounds);
        for (short i = 0; i < GameRounds; i++)
        {
            clsRoundScreen::ShowChoices(i + 1);
            Round.PlayerChoice = ReadPlayerChoice();
            Round.RoundWinner = Round.CheckWinner(i);
            Round.CalcWons();
            clsRoundScreen::ShowRoundResult(i + 1, Round.PlayerChoice,Round.ComputerChoice, Round.RoundWinner);
        }
        Round.GetFinalWinnerName();
        clsGameOverScreen::ShowEndScreen(Round);
    }




    void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }

public:

    void Play()
    {
        char Answer='y';
        for (; tolower(Answer)=='y';)
        {
            ResetScreen();
            ShowGamePlayScreen();
            cout << "\t\t\tDo You Want To Play Again [Y/N] : ";
            cin >> Answer;
        }
    }
    
};