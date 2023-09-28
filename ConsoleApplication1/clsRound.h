#pragma once
#include"clsGamePlay.h"
#include<vector>
#include<cstdlib>


class clsRound : public clsGamePlay
{
    short _PlayerChoice;
    short _ComputerChoice;
    short _RoundWinner;
    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    void GenerateComputerChoices()
    {
        _ComputerChoice = RandomNumber(0, 2);
    }

public:
 
    static enum enRoundWinner
    {
        Player = 0, Computer = 1, Draw = 2
    };
    enum enChoices
    {
        Stone = 0, Paper = 1, Scissors = 2
    };

    clsRound(short GameRounds):clsGamePlay(GameRounds)
    {

    }

    void SetPlayerChoice(short PlayerChoice)
    {
        while (PlayerChoice < 0 || PlayerChoice > 2)
        {
            cin >> PlayerChoice;
        }
        _PlayerChoice = PlayerChoice;
        GenerateComputerChoices();
    }

    enChoices GetPlayerChoice()
    {
        return (enChoices)_PlayerChoice;
    }
    __declspec(property(get = GetPlayerChoice, put = SetPlayerChoice)) enChoices PlayerChoice;

    void SetComputerChoice(short ComputerChoice)
    {
        ComputerChoice = ComputerChoice;
    }

    enChoices GetComputerChoice()
    {
        return (enChoices)_ComputerChoice;
    }
    __declspec(property(get = GetComputerChoice, put = SetComputerChoice)) enChoices ComputerChoice;

    void SetRoundWinner(short RoundWinner)
    {
        _RoundWinner = RoundWinner;
    }

    enRoundWinner GetRoundWinner()
    {
        return (enRoundWinner)_RoundWinner;
    }
    __declspec(property(get = GetRoundWinner, put = SetRoundWinner)) enRoundWinner RoundWinner;

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    enRoundWinner CheckWinner(short RoundNumber)
    {
        switch (_PlayerChoice)
        {
        case clsRound::Stone:
            switch (ComputerChoice)
            {
            case clsRound::Paper:
                return clsRound::Computer;
                break;
            case clsRound::Stone:
                return clsRound::Draw;
                break;
            case clsRound::Scissors:
                return clsRound::Player;
                break;
            default:
                break;
            }
            break;
        case clsRound::Paper:
            switch (ComputerChoice)
            {
            case clsRound::Paper:
                return clsRound::Draw;
                break;
            case clsRound::Stone:
                return clsRound::Player;
                break;
            case clsRound::Scissors:
                return clsRound::Computer;
                break;
            default:
                break;
            }
            break;
        case clsRound::Scissors:
            switch (ComputerChoice)
            {
            case clsRound::Paper:
                return clsRound::Player;
                break;
            case clsRound::Stone:
                return clsRound::Computer;
                break;
            case clsRound::Scissors:
                return clsRound::Draw;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    void CalcWons()
    {
        if (RoundWinner == clsRound::Player)
        {
            PlayerWons += 1;
        }
        else if (RoundWinner == clsRound::Computer)
        {          
            CoumputerWons += 1;
        }
        else
        {
            DrawTimes += 1;
        }
    }
};

