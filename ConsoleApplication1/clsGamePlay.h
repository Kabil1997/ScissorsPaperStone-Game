#pragma once
#include<iostream>
using namespace std;


class clsGamePlay
{

    short _GameRounds = 0;
    short _PlayerWons = 0;
    short _CoumputerWons = 0;
    short _DrawTimes = 0;
    string _FinalWinner = "";


public:
    void SetGameRounds(short GameRounds)
    {
        while (GameRounds <= 0 || GameRounds > 10)
        {
            if (GameRounds <= 0)
            {
                cout << "Your Value Less than or equal Zero\n";
                cin >> GameRounds;
            }
            else
            {
                cout << "Your Value More than Ten\n";
                cin >> GameRounds;
            }
        }
        _GameRounds = GameRounds;
    }

    short GetGameRounds()
    {
        return _GameRounds;
    }
    __declspec(property(get = GetGameRounds, put = SetGameRounds)) short GameRounds;

    void SetPlayerWons(short PlayerWons)
    {
        _PlayerWons = PlayerWons;
    }

    short GetPlayerWons()
    {
        return _PlayerWons;
    }
    __declspec(property(get = GetPlayerWons, put = SetPlayerWons)) short PlayerWons;

    void SetCoumputerWons(short CoumputerWons)
    {
        _CoumputerWons = CoumputerWons;
    }

    short GetCoumputerWons()
    {
        return _CoumputerWons;
    }
    __declspec(property(get = GetCoumputerWons, put = SetCoumputerWons)) short CoumputerWons;

    void SetDrawTimes(short DrawTimes)
    {
        _DrawTimes = DrawTimes;
    }

    short GetDrawTimes()
    {
        return _DrawTimes;
    }
    __declspec(property(get = GetDrawTimes, put = SetDrawTimes)) short DrawTimes;

    void SetFinalWinner(string FinalWinner)
    {
        _FinalWinner = FinalWinner;
    }

    string GetFinalWinner()
    {
        return _FinalWinner;
    }
    __declspec(property(get = GetFinalWinner, put = SetFinalWinner)) string FinalWinner;


    clsGamePlay(short GameRounds)
    {
        _GameRounds = GameRounds;
    }

    void GetFinalWinnerName()
    {
        PlayerWons > CoumputerWons ? FinalWinner = "Player" : PlayerWons < CoumputerWons ? FinalWinner = "Computer" : FinalWinner = "No Winner";
    }

};