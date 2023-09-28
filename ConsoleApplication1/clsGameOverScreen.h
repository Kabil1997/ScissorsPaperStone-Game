#pragma once
#include "clsGamePlay.h"
class clsGameOverScreen
{
    static void Tabs(short TabsNumber)
    {
        for (int i = 0; i < TabsNumber; i++)
        {
            cout << "\t";
        }
    }
public:
    static void ShowEndScreen(clsGamePlay Game1)
    {
        Tabs(3);
        cout << "----------------------------------------------------\n\n";
        Tabs(5);
        cout << "+++ Game Over +++\n\n";
        Tabs(3);
        cout << "----------------------------------------------------\n\n"; Tabs(3);
        cout << "--------------------[ Game Result ]-----------------\n\n"; Tabs(3);
        cout << "Game Rounds         : " << Game1.GameRounds << endl; Tabs(3);
        cout << "Player Wons times   : " << Game1.PlayerWons << endl; Tabs(3);
        cout << "Computer Wons times : " << Game1.CoumputerWons << endl; Tabs(3);
        cout << "Draw times          : " << Game1.DrawTimes << endl; Tabs(3);
        cout << "Final Winner        : " << Game1.FinalWinner << endl << endl; Tabs(3);
        cout << "----------------------------------------------------\n\n";
    }
};

