#pragma once
#include"clsRound.h"

class clsRoundScreen
{
    static void ChangeScreenColorDueToResult(clsRound::enRoundWinner RoundWinner)
    {
        if (RoundWinner == clsRound::Player)
        {
            system("Color 2F");
            return;
        }
        else if (RoundWinner == clsRound::Computer)
        {
            system("Color 4F");
            cout << "\a";
            return;
        }
        else
        {
            system("Color 0F");
        }

    }
    static const string RoundWinners[3];
    static const string Choices[3];

public:



    static void ShowChoices(short RoundNumber)
    {
        cout << "Round [" << RoundNumber << "] begins:\n\n";
        cout << "Your Choice: [1] Stone [2] Paper [3] Scissors : ";
    }
    static void ShowRoundResult(short RoundNumber, clsRound::enChoices PlayerChoice, clsRound::enChoices ComputerChoice, clsRound::enRoundWinner RoundWinner)
    {
        cout << "\n\n-------------[" << RoundNumber << "]-------------\n\n";
        cout << "Player1 Choice  : " << Choices[PlayerChoice] << endl;
        cout << "Computer Choice : " << Choices[ComputerChoice] << endl;
        cout << "Round Winner    : " << RoundWinners[RoundWinner] << endl;
        cout << "-----------------------------\n\n";
        ChangeScreenColorDueToResult(RoundWinner);
    }
};

const string clsRoundScreen::RoundWinners[3] = { "Player", "Computer", "Draw" };
const string clsRoundScreen::Choices[3] = { "Stone", "Paper", "Scissors" };
