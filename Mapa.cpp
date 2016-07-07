#define CZAS_PRACY 26
#define VERSION 2.2
#include "Mapa.h"
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <ctime>
const int MAP_SIZE = 11; //11  DO NOT CHANGE
const int MAP_SIZE2 = 12; //12 DO NOT CHANGE
const char Player1 = 'X';
const char Player2 = 'O';
const char MAP = '*';
Mapa::Mapa()
{
    CurrentPlace = 0;
    OO = new bool[9];
    XX = new bool[9];
    Map = new char*[MAP_SIZE];
    IsEmpty = new bool*[MAP_SIZE];
    int i,j;
    for(i = 0; i<9; i++)
        OO[i] = XX[i] = false;
    for(i = 0; i<MAP_SIZE; i++)
        Map[i] = new char [MAP_SIZE2];
    for(i = 0; i<MAP_SIZE; i++)
        IsEmpty[i] = new bool [MAP_SIZE2];
    for(i = 0; i<MAP_SIZE; i++)
        for(j = 0; j<MAP_SIZE2; j++)
        {
            if(i==3||i==7)
            {
                Map[i][j] = ' ';
            }
            else if((j==3||j==7)&&(i!=3||i!=7))
                Map[i][j] = '\t';
            else
                Map[i][j] = MAP;
            Map[i][MAP_SIZE2-1] = '\n';
        }

    for(i = 0; i<MAP_SIZE; i++)
        for(j = 0; j<MAP_SIZE2; j++)
            IsEmpty[i][j] = true;
    WIN = false;
}
bool Mapa::Remis()
{
    if(Map[0][0]==MAP||Map[0][1]==MAP||Map[0][2]==MAP||Map[0][4]==MAP||Map[0][5]==MAP||Map[0][6]==MAP||Map[0][8]==MAP||Map[0][9]==MAP||Map[0][10]==MAP||
            Map[1][0]==MAP||Map[1][1]==MAP||Map[1][2]==MAP||Map[1][4]==MAP||Map[1][5]==MAP||Map[1][6]==MAP||Map[1][8]==MAP||Map[1][9]==MAP||Map[1][10]==MAP||
            Map[2][0]==MAP||Map[2][1]==MAP||Map[2][2]==MAP||Map[2][4]==MAP||Map[2][5]==MAP||Map[2][6]==MAP||Map[2][8]==MAP||Map[2][9]==MAP||Map[2][10]==MAP||
            Map[4][0]==MAP||Map[4][1]==MAP||Map[4][2]==MAP||Map[4][4]==MAP||Map[4][5]==MAP||Map[4][6]==MAP||Map[4][8]==MAP||Map[4][9]==MAP||Map[4][10]==MAP||
            Map[5][0]==MAP||Map[5][1]==MAP||Map[5][2]==MAP||Map[5][4]==MAP||Map[5][5]==MAP||Map[5][6]==MAP||Map[5][8]==MAP||Map[5][9]==MAP||Map[5][10]==MAP||
            Map[6][0]==MAP||Map[6][1]==MAP||Map[6][2]==MAP||Map[6][4]==MAP||Map[6][5]==MAP||Map[6][6]==MAP||Map[6][8]==MAP||Map[6][9]==MAP||Map[6][10]==MAP||
            Map[8][0]==MAP||Map[8][1]==MAP||Map[8][2]==MAP||Map[8][4]==MAP||Map[8][5]==MAP||Map[8][6]==MAP||Map[8][8]==MAP||Map[8][9]==MAP||Map[8][10]==MAP||
            Map[9][0]==MAP||Map[9][1]==MAP||Map[9][2]==MAP||Map[9][4]==MAP||Map[9][5]==MAP||Map[9][6]==MAP||Map[9][8]==MAP||Map[9][9]==MAP||Map[9][10]==MAP||
            Map[10][0]==MAP||Map[10][1]==MAP||Map[10][2]==MAP||Map[10][4]==MAP||Map[10][5]==MAP||Map[10][6]==MAP||Map[10][8]==MAP||Map[10][9]==MAP||Map[10][10]==MAP)
        return false;
    else return true;
    return true;
}
void Mapa::Start() //Glowne sterowanie
{
    srand(time(0));
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char choice;
    system("Title Tic Tac Toe");
    do
    {
        system("cls");
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
        cout<<R"(       _         _    _ _    _        _         _   __    _ _  )"<<endl;
        cout<<R"(     /  \      / /  /  _ /  / /     /  \      / /  /_/  / _ _ \)"<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        cout<<R"(    / /\ \    / /  / /_    / /     / /\ \    / /  __   / /__/ /)"<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
        cout<<R"(   / /  \ \  / /  /  _ /  / /     / /  \ \  / /  / /  /  __  / )"<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        cout<<R"(  / /    \ \/ /  / /_    / /_ _  / /    \ \/ /  / /  / /   \ \ )"<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
        cout<<R"( /_/      \_ /  /_ _ /  /_ _ _/ /_/      \_ /  /_/  /_/     \_\)"<<endl<<endl;
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
        cout<<"[Player vs Player]-2\n";
        cout<<"[Player vs Bot]-1\n";
        cout<<"[Exit]-0\n";
        cout<<"->";
        cin.sync();
        do
        {
            choice = getch();
            choice-=48;
        }
        while(choice!=1&&choice!=2&&choice!=72&&choice!=40&&choice!=0);
        if(choice==1||choice==2)
            cout<<int(choice)<<endl;
        else
        {
            choice+=48;
            cout<<choice<<endl;
            choice-=48;
        }
        Sleep(400);
        if(choice==2)
        {
            do
            {
                system("cls");
                cout<<*this;
                this->Ruch(Player1);
                if(CheckSmallWin(Player1))
                    if(CheckWin())
                    {
                        system("cls");
                        cout<<*this;
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                        cout<<"\nWygrywa gracz: ";
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                        cout<<Player1<<"\n";
                        system("pause");
                        continue;
                    }
                if(Remis())
                {
                    system("cls");
                    cout<<*this;
                    WIN=true;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\nREMIS\n";
                    system("pause");
                    continue;
                }
                system("cls");
                cout<<*this;
                this->Ruch(Player2);
                if(CheckSmallWin(Player2))
                    if(CheckWin())
                    {
                        system("cls");
                        cout<<*this;
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                        cout<<"\nWygrywa gracz: ";
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                        cout<<Player2<<"\n";
                        system("pause");
                        continue;
                    }
                if(Remis())
                {
                    system("cls");
                    cout<<*this;
                    WIN=true;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                    cout<<"\nREMIS\n";
                    system("pause");
                    continue;
                }
            }
            while(WIN==false);
            Reset();
        }
        else if(choice==40||choice==72)
        {
            system("cls");
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            cout<<"Autor: ";
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            cout<<"Marcin Dzieci\245tkowski\n";
            SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            cout<<"Czas pracy: "<<CZAS_PRACY<<"h"<<endl;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
            cout<<"Pomocnik: LerionQ\n";
            SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
            cout<<"Data ostatecznej kompilacji: 06.07.2016"<<endl;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            cout<<"Wersja: "<<VERSION<<endl;
            getch();
        }
        else if(choice==1)
        {
            Bot();
            Reset();
        }
    }
    while(choice!=0);
    SetConsoleTextAttribute(hOut,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
    cout<<"Do widzenia :)";
    Sleep(1000);
}
void Mapa::Bot()
{

    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
        system("cls");
        cout<<*this;
        this->Ruch(Player1);
        if(CheckSmallWin(Player1))
            if(CheckWin())
            {
                system("cls");
                cout<<*this;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"\nWygrywa gracz: ";
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<Player1<<"\n";
                system("pause");
                continue;
            }
        if(Remis())
        {
            system("cls");
            cout<<*this;
            WIN=true;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            cout<<"REMIS\n";
            system("pause");
            continue;
        }
        system("cls");
        cout<<*this;
        this->RuchBot(Player2);
        if(CheckSmallWin(Player2))
            if(CheckWin())
            {
                system("cls");
                cout<<*this;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"\nWygrywa gracz: ";
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<Player2<<"\n";
                system("pause");
                continue;
            }
        if(Remis())
        {
            system("cls");
            cout<<*this;
            WIN=true;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
            cout<<"REMIS\n";
            system("pause");
            continue;
        }
    }
    while(WIN==false);
}
void Mapa::RuchBot(const char kr)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout<<"Gracz: ";
    if(kr==Player1)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout<<kr<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    int y, x, a;
    Sleep(1000);
    switch(CurrentPlace)
    {
    case 1:
        do
        {
            if(((Map[0][1]==Map[0][2]&&Map[0][2]==Player1)||(Map[1][0]==Map[2][0]&&Map[2][0]==Player1)||(Map[1][1]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[0][0])
            {
                x=1;
                y=1;
            }
            else if(((Map[0][0]==Map[0][2]&&Map[0][0]==Player1)||(Map[1][1]==Map[2][1]&&Map[2][1]==Player1))&&IsEmpty[0][1])
            {
                x=2;
                y=1;
            }
            else if(((Map[0][0]==Map[0][1]&&Map[0][1]==Player1)||(Map[1][1]==Map[2][0]&&Map[2][0]==Player1)||(Map[1][2]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[0][2])
            {
                x=3;
                y=1;
            }
            else if(((Map[0][0]==Map[2][0]&&Map[0][0]==Player1)||(Map[1][1]==Map[1][2]&&Map[1][2]==Player1))&&IsEmpty[1][0])
            {
                x=1;
                y=2;
            }
            else if(((Map[0][0]==Map[2][2]&&Map[0][0]==Player1)||(Map[2][0]==Map[0][2]&&Map[0][2]==Player1)||(Map[1][0]==Map[1][2]&&Map[1][2]==Player1)||(Map[0][1]==Map[2][1]&&Map[2][1]==Player1))&&IsEmpty[1][1])
            {
                x=2;
                y=2;
            }
            else if(((Map[1][0]==Map[1][1]&&Map[1][1]==Player1)||(Map[0][2]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[1][2])
            {
                x=3;
                y=2;
            }
            else if(((Map[0][0]==Map[1][0]&&Map[1][0]==Player1)||(Map[2][1]==Map[2][2]&&Map[2][2]==Player1)||(Map[0][2]==Map[1][1]&&Map[1][1]==Player1))&&IsEmpty[2][0])
            {
                x=1;
                y=3;
            }
            else if(((Map[0][1]==Map[1][1]&&Map[5][1]==Player1)||(Map[2][0]==Map[2][2]&&Map[2][0]==Player1))&&IsEmpty[2][1])
            {
                x=2;
                y=3;
            }
            else if(((Map[0][0]==Map[1][1]&&Map[1][1]==Player1)||(Map[2][0]==Map[2][1]&&Map[2][0]==Player1)||(Map[0][2]==Map[1][2]&&Map[1][2]==Player1))&&IsEmpty[2][2])
            {
                x=3;
                y=3;
            }
            else             if(((Map[0][1]==Map[0][2]&&Map[0][2]==kr)||(Map[1][0]==Map[2][0]&&Map[2][0]==kr)||(Map[1][1]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[0][0])
            {
                x=1;
                y=1;
            }
            else if(((Map[0][0]==Map[0][2]&&Map[0][0]==kr)||(Map[1][1]==Map[2][1]&&Map[2][1]==kr))&&IsEmpty[0][1])
            {
                x=2;
                y=1;
            }
            else if(((Map[0][0]==Map[0][1]&&Map[0][1]==kr)||(Map[1][1]==Map[2][0]&&Map[2][0]==kr)||(Map[1][2]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[0][2])
            {
                x=3;
                y=1;
            }
            else if(((Map[0][0]==Map[2][0]&&Map[0][0]==kr)||(Map[1][1]==Map[1][2]&&Map[1][2]==kr))&&IsEmpty[1][0])
            {
                x=1;
                y=2;
            }
            else if(((Map[0][0]==Map[2][2]&&Map[0][0]==kr)||(Map[2][0]==Map[0][2]&&Map[0][2]==kr)||(Map[1][0]==Map[1][2]&&Map[1][2]==kr)||(Map[0][1]==Map[2][1]&&Map[2][1]==kr))&&IsEmpty[1][1])
            {
                x=2;
                y=2;
            }
            else if(((Map[1][0]==Map[1][1]&&Map[1][1]==kr)||(Map[0][2]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[1][2])
            {
                x=3;
                y=2;
            }
            else if(((Map[0][0]==Map[1][0]&&Map[1][0]==kr)||(Map[2][1]==Map[2][2]&&Map[2][2]==kr)||(Map[0][2]==Map[1][1]&&Map[1][1]==kr))&&IsEmpty[2][0])
            {
                x=1;
                y=3;
            }
            else if(((Map[0][1]==Map[1][1]&&Map[5][1]==kr)||(Map[2][0]==Map[2][2]&&Map[2][0]==kr))&&IsEmpty[2][1])
            {
                x=2;
                y=3;
            }
            else if(((Map[0][0]==Map[1][1]&&Map[1][1]==kr)||(Map[2][0]==Map[2][1]&&Map[2][0]==kr)||(Map[0][2]==Map[1][2]&&Map[1][2]==kr))&&IsEmpty[2][2])
            {
                x=3;
                y=3;
            }
            else
            {
                do
                {
                x = (rand()%3)+1;
                y = (rand()%3)+1;
                a = rand()%100+1;
                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 2:
        do
        {
            if(((Map[4][1]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][0]==Map[6][0]&&Map[5][0]==Player1)||(Map[5][1]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[3][0])
            {
                x=1;
                y=4;
            }
            else if(((Map[4][0]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][1]==Map[6][1]&&Map[5][1]==Player1))&&IsEmpty[3][1])
            {
                x=2;
                y=4;
            }
            else if(((Map[4][0]==Map[4][1]&&Map[4][1]==Player1)||(Map[5][1]==Map[6][0]&&Map[6][0]==Player1)||(Map[5][2]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[3][2])
            {
                x=3;
                y=4;
            }
            else if(((Map[4][0]==Map[6][0]&&Map[4][0]==Player1)||(Map[5][1]==Map[5][2]&&Map[5][2]==Player1))&&IsEmpty[4][0])
            {
                x=1;
                y=5;
            }
            else if(((Map[4][0]==Map[6][2]&&Map[4][0]==Player1)||(Map[6][0]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][0]==Map[5][2]&&Map[5][2]==Player1)||(Map[4][1]==Map[6][1]&&Map[4][1]==Player1))&&IsEmpty[4][1])
            {
                x=2;
                y=5;
            }
            else if(((Map[5][0]==Map[5][1]&&Map[5][1]==Player1)||(Map[4][2]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[4][2])
            {
                x=3;
                y=5;
            }
            else if(((Map[4][0]==Map[5][0]&&Map[5][0]==Player1)||(Map[6][1]==Map[6][2]&&Map[6][2]==Player1)||(Map[4][2]==Map[5][1]&&Map[5][1]==Player1))&&IsEmpty[5][0])
            {
                x=1;
                y=6;
            }
            else if(((Map[4][1]==Map[5][1]&&Map[5][1]==Player1)||(Map[6][0]==Map[6][2]&&Map[6][0]==Player1))&&IsEmpty[5][1])
            {
                x=2;
                y=6;
            }
            else if(((Map[4][0]==Map[5][1]&&Map[5][1]==Player1)||(Map[6][0]==Map[6][1]&&Map[6][0]==Player1)||(Map[4][2]==Map[5][2]&&Map[5][2]==Player1))&&IsEmpty[5][2])
            {
                x=3;
                y=6;
            }
            else             if(((Map[4][1]==Map[4][2]&&Map[4][2]==kr)||(Map[5][0]==Map[6][0]&&Map[5][0]==kr)||(Map[5][1]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[3][0])
            {
                x=1;
                y=4;
            }
            else if(((Map[4][0]==Map[4][2]&&Map[4][2]==kr)||(Map[5][1]==Map[6][1]&&Map[5][1]==kr))&&IsEmpty[3][1])
            {
                x=2;
                y=4;
            }
            else if(((Map[4][0]==Map[4][1]&&Map[4][1]==kr)||(Map[5][1]==Map[6][0]&&Map[6][0]==kr)||(Map[5][2]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[3][2])
            {
                x=3;
                y=4;
            }
            else if(((Map[4][0]==Map[6][0]&&Map[4][0]==kr)||(Map[5][1]==Map[5][2]&&Map[5][2]==kr))&&IsEmpty[4][0])
            {
                x=1;
                y=5;
            }
            else if(((Map[4][0]==Map[6][2]&&Map[4][0]==kr)||(Map[6][0]==Map[4][2]&&Map[4][2]==kr)||(Map[5][0]==Map[5][2]&&Map[5][2]==kr)||(Map[4][1]==Map[6][1]&&Map[4][1]==kr))&&IsEmpty[4][1])
            {
                x=2;
                y=5;
            }
            else if(((Map[5][0]==Map[5][1]&&Map[5][1]==kr)||(Map[4][2]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[4][2])
            {
                x=3;
                y=5;
            }
            else if(((Map[4][0]==Map[5][0]&&Map[5][0]==kr)||(Map[6][1]==Map[6][2]&&Map[6][2]==kr)||(Map[4][2]==Map[5][1]&&Map[5][1]==kr))&&IsEmpty[5][0])
            {
                x=1;
                y=6;
            }
            else if(((Map[4][1]==Map[5][1]&&Map[5][1]==kr)||(Map[6][0]==Map[6][2]&&Map[6][0]==kr))&&IsEmpty[5][1])
            {
                x=2;
                y=6;
            }
            else if(((Map[4][0]==Map[5][1]&&Map[5][1]==kr)||(Map[6][0]==Map[6][1]&&Map[6][0]==kr)||(Map[4][2]==Map[5][2]&&Map[5][2]==kr))&&IsEmpty[5][2])
            {
                x=3;
                y=6;
            }
            else
            {
                do{
                x = (rand()%3)+1;
                y = (rand()%3)+4;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 3:
        do
        {
            if(((Map[8][1]==Map[8][2]&&Map[8][2]==Player1)||(Map[9][0]==Map[10][0]&&Map[9][0]==Player1)||(Map[9][1]==Map[10][2]&&Map[10][2]==Player1))&&IsEmpty[6][0])
            {
                x=1;
                y=7;
            }
            else if(((Map[8][0]==Map[8][2]&&Map[8][2]==Player1)||(Map[9][1]==Map[10][1]&&Map[10][1]==Player1))&&IsEmpty[6][1])
            {
                x=2;
                y=7;
            }
            else if(((Map[8][0]==Map[8][1]&&Map[8][1]==Player1)||(Map[9][1]==Map[10][0]&&Map[10][0]==Player1)||(Map[9][2]==Map[10][2]&&Map[9][2]==Player1))&&IsEmpty[6][2])
            {
                x=3;
                y=7;
            }
            else if(((Map[8][0]==Map[9][0]&&Map[9][0]==Player1)||(Map[9][1]==Map[9][2]&&Map[9][2]==Player1))&&IsEmpty[7][0])
            {
                x=1;
                y=8;
            }
            else if(((Map[8][0]==Map[10][2]&&Map[8][0]==Player1)||(Map[10][0]==Map[8][2]&&Map[8][2]==Player1)||(Map[9][0]==Map[9][2]&&Map[9][2]==Player1)||(Map[8][1]==Map[10][1]&&Map[10][1]==Player1))&&IsEmpty[7][1])
            {
                x=2;
                y=8;
            }
            else if(((Map[9][0]==Map[9][1]&&Map[9][1]==Player1)||(Map[8][2]==Map[10][2]&&Map[10][2]==Player1))&&IsEmpty[7][2])
            {
                x=3;
                y=8;
            }
            else if(((Map[8][0]==Map[9][0]&&Map[9][0]==Player1)||(Map[10][1]==Map[10][2]&&Map[10][2]==Player1)||(Map[8][2]==Map[9][1]&&Map[9][1]==Player1))&&IsEmpty[8][0])
            {
                x=1;
                y=9;
            }
            else if(((Map[8][1]==Map[9][1]&&Map[9][1]==Player1)||(Map[10][0]==Map[10][2]&&Map[10][0]==Player1))&&IsEmpty[8][1])
            {
                x=2;
                y=9;
            }
            else if(((Map[10][0]==Map[10][1]&&Map[10][1]==Player1)||(Map[8][0]==Map[9][1]&&Map[9][1]==Player1)||(Map[8][2]==Map[9][2]&&Map[9][2]==Player1))&&IsEmpty[8][2])
            {
                x=3;
                y=9;
            }
            else             if(((Map[8][1]==Map[8][2]&&Map[8][2]==kr)||(Map[9][0]==Map[10][0]&&Map[9][0]==kr)||(Map[9][1]==Map[10][2]&&Map[10][2]==kr))&&IsEmpty[6][0])
            {
                x=1;
                y=7;
            }
            else if(((Map[8][0]==Map[8][2]&&Map[8][2]==kr)||(Map[9][1]==Map[10][1]&&Map[10][1]==kr))&&IsEmpty[6][1])
            {
                x=2;
                y=7;
            }
            else if(((Map[8][0]==Map[8][1]&&Map[8][1]==kr)||(Map[9][1]==Map[10][0]&&Map[10][0]==kr)||(Map[9][2]==Map[10][2]&&Map[9][2]==kr))&&IsEmpty[6][2])
            {
                x=3;
                y=7;
            }
            else if(((Map[8][0]==Map[9][0]&&Map[9][0]==kr)||(Map[9][1]==Map[9][2]&&Map[9][2]==kr))&&IsEmpty[7][0])
            {
                x=1;
                y=8;
            }
            else if(((Map[8][0]==Map[10][2]&&Map[8][0]==kr)||(Map[10][0]==Map[8][2]&&Map[8][2]==kr)||(Map[9][0]==Map[9][2]&&Map[9][2]==kr)||(Map[8][1]==Map[10][1]&&Map[10][1]==kr))&&IsEmpty[7][1])
            {
                x=2;
                y=8;
            }
            else if(((Map[9][0]==Map[9][1]&&Map[9][1]==kr)||(Map[8][2]==Map[10][2]&&Map[10][2]==kr))&&IsEmpty[7][2])
            {
                x=3;
                y=8;
            }
            else if(((Map[8][0]==Map[9][0]&&Map[9][0]==kr)||(Map[10][1]==Map[10][2]&&Map[10][2]==kr)||(Map[8][2]==Map[9][1]&&Map[9][1]==kr))&&IsEmpty[8][0])
            {
                x=1;
                y=9;
            }
            else if(((Map[8][1]==Map[9][1]&&Map[9][1]==kr)||(Map[10][0]==Map[10][2]&&Map[10][0]==kr))&&IsEmpty[8][1])
            {
                x=2;
                y=9;
            }
            else if(((Map[10][0]==Map[10][1]&&Map[10][1]==kr)||(Map[8][0]==Map[9][1]&&Map[9][1]==kr)||(Map[8][2]==Map[9][2]&&Map[9][2]==kr))&&IsEmpty[8][2])
            {
                x=3;
                y=9;
            }
            else
            {
                do{
                x = (rand()%3)+1;
                y = (rand()%3)+7;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 4:
        do
        {
            if(((Map[0][5]==Map[0][6]&&Map[0][5]==Player1)||(Map[1][4]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][5]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[0][3])
            {
                x=4;
                y=1;
            }
            else if(((Map[0][4]==Map[0][6]&&Map[0][4]==Player1)||(Map[1][5]==Map[2][5]&&Map[2][5]==Player1))&&IsEmpty[0][4])
            {
                x=5;
                y=1;
            }
            else if(((Map[0][4]==Map[0][5]&&Map[0][5]==Player1)||(Map[1][5]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][6]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[0][5])
            {
                x=6;
                y=1;
            }
            else if(((Map[0][4]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][5]==Map[1][6]&&Map[1][6]==Player1))&&IsEmpty[1][3])
            {
                x=4;
                y=2;
            }
            else if(((Map[0][4]==Map[2][6]&&Map[0][4]==Player1)||(Map[2][4]==Map[0][6]&&Map[0][6]==Player1)||(Map[1][4]==Map[1][6]&&Map[1][6]==Player1)||(Map[0][5]==Map[2][5]&&Map[2][5]==Player1))&&IsEmpty[1][4])
            {
                x=5;
                y=2;
            }
            else if(((Map[1][4]==Map[1][5]&&Map[1][5]==Player1)||(Map[0][6]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[1][5])
            {
                x=6;
                y=2;
            }
            else if(((Map[0][4]==Map[1][4]&&Map[1][4]==Player1)||(Map[2][5]==Map[2][6]&&Map[2][5]==Player1)||(Map[0][6]==Map[1][5]&&Map[1][5]==Player1))&&IsEmpty[2][3])
            {
                x=4;
                y=3;
            }
            else if(((Map[0][5]==Map[1][5]&&Map[1][5]==Player1)||(Map[2][4]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[2][4])
            {
                x=5;
                y=3;
            }
            else if(((Map[0][4]==Map[1][5]&&Map[1][5]==Player1)||(Map[2][4]==Map[2][5]&&Map[2][5]==Player1)||(Map[0][6]==Map[1][6]&&Map[1][6]==Player1))&&IsEmpty[2][5])
            {
                x=6;
                y=3;
            }
            else             if(((Map[0][5]==Map[0][6]&&Map[0][5]==kr)||(Map[1][4]==Map[2][4]&&Map[2][4]==kr)||(Map[1][5]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[0][3])
            {
                x=4;
                y=1;
            }
            else if(((Map[0][4]==Map[0][6]&&Map[0][4]==kr)||(Map[1][5]==Map[2][5]&&Map[2][5]==kr))&&IsEmpty[0][4])
            {
                x=5;
                y=1;
            }
            else if(((Map[0][4]==Map[0][5]&&Map[0][5]==kr)||(Map[1][5]==Map[2][4]&&Map[2][4]==kr)||(Map[1][6]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[0][5])
            {
                x=6;
                y=1;
            }
            else if(((Map[0][4]==Map[2][4]&&Map[2][4]==kr)||(Map[1][5]==Map[1][6]&&Map[1][6]==kr))&&IsEmpty[1][3])
            {
                x=4;
                y=2;
            }
            else if(((Map[0][4]==Map[2][6]&&Map[0][4]==kr)||(Map[2][4]==Map[0][6]&&Map[0][6]==kr)||(Map[1][4]==Map[1][6]&&Map[1][6]==kr)||(Map[0][5]==Map[2][5]&&Map[2][5]==kr))&&IsEmpty[1][4])
            {
                x=5;
                y=2;
            }
            else if(((Map[1][4]==Map[1][5]&&Map[1][5]==kr)||(Map[0][6]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[1][5])
            {
                x=6;
                y=2;
            }
            else if(((Map[0][4]==Map[1][4]&&Map[1][4]==kr)||(Map[2][5]==Map[2][6]&&Map[2][5]==kr)||(Map[0][6]==Map[1][5]&&Map[1][5]==kr))&&IsEmpty[2][3])
            {
                x=4;
                y=3;
            }
            else if(((Map[0][5]==Map[1][5]&&Map[1][5]==kr)||(Map[2][4]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[2][4])
            {
                x=5;
                y=3;
            }
            else if(((Map[0][4]==Map[1][5]&&Map[1][5]==kr)||(Map[2][4]==Map[2][5]&&Map[2][5]==kr)||(Map[0][6]==Map[1][6]&&Map[1][6]==kr))&&IsEmpty[2][5])
            {
                x=6;
                y=3;
            }
            else
            {
                do{
                x = (rand()%3)+4;
                y = (rand()%3)+1;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 5:
        do
        {
            if(((Map[4][5]==Map[4][6]&&Map[4][5]==Player1)||(Map[5][4]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][5]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[3][3])
            {
                x=4;
                y=4;
            }
            else if(((Map[4][4]==Map[4][6]&&Map[4][4]==Player1)||(Map[5][5]==Map[6][5]&&Map[6][5]==Player1))&&IsEmpty[3][4])
            {
                x=5;
                y=4;
            }
            else if(((Map[4][4]==Map[4][5]&&Map[4][5]==Player1)||(Map[5][5]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][6]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[3][5])
            {
                x=6;
                y=4;
            }
            else if(((Map[4][4]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][5]==Map[5][6]&&Map[5][6]==Player1))&&IsEmpty[4][3])
            {
                x=4;
                y=5;
            }
            else if(((Map[4][4]==Map[6][6]&&Map[4][4]==Player1)||(Map[6][4]==Map[5][6]&&Map[5][6]==Player1)||(Map[5][4]==Map[5][6]&&Map[5][6]==Player1)||(Map[4][5]==Map[6][5]&&Map[5][5]==Player1))&&IsEmpty[4][4])
            {
                x=5;
                y=5;
            }
            else if(((Map[5][4]==Map[5][5]&&Map[5][5]==Player1)||(Map[4][6]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[4][5])
            {
                x=6;
                y=5;
            }
            else if(((Map[4][4]==Map[5][4]&&Map[4][4]==Player1)||(Map[6][5]==Map[6][6]&&Map[6][6]==Player1)||(Map[4][6]==Map[5][5]&&Map[5][5]==Player1))&&IsEmpty[5][3])
            {
                x=4;
                y=6;
            }
            else if(((Map[4][5]==Map[5][5]&&Map[5][5]==Player1)||(Map[6][4]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[5][4])
            {
                x=5;
                y=6;
            }
            else if(((Map[4][4]==Map[5][5]&&Map[5][5]==Player1)||(Map[6][4]==Map[6][5]&&Map[2][5]==Player1)||(Map[4][6]==Map[5][6]&&Map[5][6]==Player1))&&IsEmpty[5][5])
            {
                x=6;
                y=6;
            }
            else             if(((Map[4][5]==Map[4][6]&&Map[4][5]==kr)||(Map[5][4]==Map[6][4]&&Map[6][4]==kr)||(Map[5][5]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[3][3])
            {
                x=4;
                y=4;
            }
            else if(((Map[4][4]==Map[4][6]&&Map[4][4]==kr)||(Map[5][5]==Map[6][5]&&Map[6][5]==kr))&&IsEmpty[3][4])
            {
                x=5;
                y=4;
            }
            else if(((Map[4][4]==Map[4][5]&&Map[4][5]==kr)||(Map[5][5]==Map[6][4]&&Map[6][4]==kr)||(Map[5][6]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[3][5])
            {
                x=6;
                y=4;
            }
            else if(((Map[4][4]==Map[6][4]&&Map[6][4]==kr)||(Map[5][5]==Map[5][6]&&Map[5][6]==kr))&&IsEmpty[4][3])
            {
                x=4;
                y=5;
            }
            else if(((Map[4][4]==Map[6][6]&&Map[4][4]==kr)||(Map[6][4]==Map[5][6]&&Map[5][6]==kr)||(Map[5][4]==Map[5][6]&&Map[5][6]==kr)||(Map[4][5]==Map[6][5]&&Map[5][5]==kr))&&IsEmpty[4][4])
            {
                x=5;
                y=5;
            }
            else if(((Map[5][4]==Map[5][5]&&Map[5][5]==kr)||(Map[4][6]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[4][5])
            {
                x=6;
                y=5;
            }
            else if(((Map[4][4]==Map[5][4]&&Map[4][4]==kr)||(Map[6][5]==Map[6][6]&&Map[6][6]==kr)||(Map[4][6]==Map[5][5]&&Map[5][5]==kr))&&IsEmpty[5][3])
            {
                x=4;
                y=6;
            }
            else if(((Map[4][5]==Map[5][5]&&Map[5][5]==kr)||(Map[6][4]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[5][4])
            {
                x=5;
                y=6;
            }
            else if(((Map[4][4]==Map[5][5]&&Map[5][5]==kr)||(Map[6][4]==Map[6][5]&&Map[2][5]==kr)||(Map[4][6]==Map[5][6]&&Map[5][6]==kr))&&IsEmpty[5][5])
            {
                x=6;
                y=6;
            }
            else
            {
                do{
                x = (rand()%3)+4;
                y = (rand()%3)+4;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 6:
        do
        {
            if(((Map[8][5]==Map[8][6]&&Map[8][5]==Player1)||(Map[8][4]==Map[9][4]&&Map[9][4]==Player1)||(Map[9][5]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[6][3])
            {
                x=4;
                y=7;
            }
            else if(((Map[8][4]==Map[8][6]&&Map[8][4]==Player1)||(Map[9][5]==Map[10][5]&&Map[10][5]==Player1))&&IsEmpty[6][4])
            {
                x=5;
                y=7;
            }
            else if(((Map[8][4]==Map[8][5]&&Map[8][5]==Player1)||(Map[9][5]==Map[10][4]&&Map[10][4]==Player1)||(Map[9][6]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[6][5])
            {
                x=6;
                y=7;
            }
            else if(((Map[8][4]==Map[10][4]&&Map[10][4]==Player1)||(Map[9][5]==Map[9][6]&&Map[9][6]==Player1))&&IsEmpty[7][3])
            {
                x=4;
                y=8;
            }
            else if(((Map[8][4]==Map[10][6]&&Map[8][4]==Player1)||(Map[10][4]==Map[9][6]&&Map[9][6]==Player1)||(Map[9][4]==Map[9][6]&&Map[9][6]==Player1)||(Map[8][5]==Map[10][5]&&Map[5][5]==Player1))&&IsEmpty[7][4])
            {
                x=5;
                y=8;
            }
            else if(((Map[9][4]==Map[9][5]&&Map[9][5]==Player1)||(Map[8][6]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[7][5])
            {
                x=6;
                y=8;
            }
            else if(((Map[8][4]==Map[9][4]&&Map[9][4]==Player1)||(Map[10][5]==Map[10][6]&&Map[10][6]==Player1)||(Map[8][6]==Map[9][5]&&Map[9][5]==Player1))&&IsEmpty[8][3])
            {
                x=4;
                y=9;
            }
            else if(((Map[8][5]==Map[9][5]&&Map[9][5]==Player1)||(Map[10][4]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[8][4])
            {
                x=5;
                y=9;
            }
            else if(((Map[8][4]==Map[9][5]&&Map[9][5]==Player1)||(Map[10][4]==Map[10][5]&&Map[10][5]==Player1)||(Map[8][6]==Map[9][6]&&Map[9][6]==Player1))&&IsEmpty[8][5])
            {
                x=6;
                y=9;
            }
            else             if(((Map[8][5]==Map[8][6]&&Map[8][5]==kr)||(Map[8][4]==Map[9][4]&&Map[9][4]==kr)||(Map[9][5]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[6][3])
            {
                x=4;
                y=7;
            }
            else if(((Map[8][4]==Map[8][6]&&Map[8][4]==kr)||(Map[9][5]==Map[10][5]&&Map[10][5]==kr))&&IsEmpty[6][4])
            {
                x=5;
                y=7;
            }
            else if(((Map[8][4]==Map[8][5]&&Map[8][5]==kr)||(Map[9][5]==Map[10][4]&&Map[10][4]==kr)||(Map[9][6]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[6][5])
            {
                x=6;
                y=7;
            }
            else if(((Map[8][4]==Map[10][4]&&Map[10][4]==kr)||(Map[9][5]==Map[9][6]&&Map[9][6]==kr))&&IsEmpty[7][3])
            {
                x=4;
                y=8;
            }
            else if(((Map[8][4]==Map[10][6]&&Map[8][4]==kr)||(Map[10][4]==Map[9][6]&&Map[9][6]==kr)||(Map[9][4]==Map[9][6]&&Map[9][6]==kr)||(Map[8][5]==Map[10][5]&&Map[5][5]==kr))&&IsEmpty[7][4])
            {
                x=5;
                y=8;
            }
            else if(((Map[9][4]==Map[9][5]&&Map[9][5]==kr)||(Map[8][6]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[7][5])
            {
                x=6;
                y=8;
            }
            else if(((Map[8][4]==Map[9][4]&&Map[9][4]==kr)||(Map[10][5]==Map[10][6]&&Map[10][6]==kr)||(Map[8][6]==Map[9][5]&&Map[9][5]==kr))&&IsEmpty[8][3])
            {
                x=4;
                y=9;
            }
            else if(((Map[8][5]==Map[9][5]&&Map[9][5]==kr)||(Map[10][4]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[8][4])
            {
                x=5;
                y=9;
            }
            else if(((Map[8][4]==Map[9][5]&&Map[9][5]==kr)||(Map[10][4]==Map[10][5]&&Map[10][5]==kr)||(Map[8][6]==Map[9][6]&&Map[9][6]==kr))&&IsEmpty[8][5])
            {
                x=6;
                y=9;
            }
            else
            {
                do{
                x = (rand()%3)+4;
                y = (rand()%3)+7;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 7:
        do
        {
            if(((Map[0][9]==Map[0][10]&&Map[0][9]==Player1)||(Map[1][8]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][9]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[0][6])
            {
                x=7;
                y=1;
            }
            else if(((Map[0][8]==Map[0][10]&&Map[0][8]==Player1)||(Map[1][9]==Map[2][9]&&Map[2][9]==Player1))&&IsEmpty[0][7])
            {
                x=8;
                y=1;
            }
            else if(((Map[0][8]==Map[0][9]&&Map[0][8]==Player1)||(Map[1][9]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][10]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[0][8])
            {
                x=9;
                y=1;
            }
            else if(((Map[0][8]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][9]==Map[1][10]&&Map[1][10]==Player1))&&IsEmpty[1][6])
            {
                x=7;
                y=2;
            }
            else if(((Map[0][8]==Map[2][10]&&Map[0][8]==Player1)||(Map[2][8]==Map[0][10]&&Map[0][10]==Player1)||(Map[1][8]==Map[1][10]&&Map[1][10]==Player1)||(Map[0][9]==Map[2][9]&&Map[2][9]==Player1))&&IsEmpty[1][7])
            {
                x=8;
                y=2;
            }
            else if(((Map[1][8]==Map[1][9]&&Map[1][9]==Player1)||(Map[0][10]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[1][8])
            {
                x=9;
                y=2;
            }
            else if(((Map[0][8]==Map[1][8]&&Map[1][8]==Player1)||(Map[2][9]==Map[2][10]&&Map[2][9]==Player1)||(Map[0][10]==Map[1][9]&&Map[1][9]==Player1))&&IsEmpty[2][6])
            {
                x=7;
                y=3;
            }
            else if(((Map[0][9]==Map[1][9]&&Map[1][9]==Player1)||(Map[2][8]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[2][7])
            {
                x=8;
                y=3;
            }
            else if(((Map[0][8]==Map[1][9]&&Map[1][9]==Player1)||(Map[2][8]==Map[2][9]&&Map[2][9]==Player1)||(Map[0][10]==Map[1][10]&&Map[1][10]==Player1))&&IsEmpty[2][8])
            {
                x=9;
                y=3;
            }
            else             if(((Map[0][9]==Map[0][10]&&Map[0][9]==kr)||(Map[1][8]==Map[2][8]&&Map[2][8]==kr)||(Map[1][9]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[0][6])
            {
                x=7;
                y=1;
            }
            else if(((Map[0][8]==Map[0][10]&&Map[0][8]==kr)||(Map[1][9]==Map[2][9]&&Map[2][9]==kr))&&IsEmpty[0][7])
            {
                x=8;
                y=1;
            }
            else if(((Map[0][8]==Map[0][9]&&Map[0][8]==kr)||(Map[1][9]==Map[2][8]&&Map[2][8]==kr)||(Map[1][10]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[0][8])
            {
                x=9;
                y=1;
            }
            else if(((Map[0][8]==Map[2][8]&&Map[2][8]==kr)||(Map[1][9]==Map[1][10]&&Map[1][10]==kr))&&IsEmpty[1][6])
            {
                x=7;
                y=2;
            }
            else if(((Map[0][8]==Map[2][10]&&Map[0][8]==kr)||(Map[2][8]==Map[0][10]&&Map[0][10]==kr)||(Map[1][8]==Map[1][10]&&Map[1][10]==kr)||(Map[0][9]==Map[2][9]&&Map[2][9]==kr))&&IsEmpty[1][7])
            {
                x=8;
                y=2;
            }
            else if(((Map[1][8]==Map[1][9]&&Map[1][9]==kr)||(Map[0][10]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[1][8])
            {
                x=9;
                y=2;
            }
            else if(((Map[0][8]==Map[1][8]&&Map[1][8]==kr)||(Map[2][9]==Map[2][10]&&Map[2][9]==kr)||(Map[0][10]==Map[1][9]&&Map[1][9]==kr))&&IsEmpty[2][6])
            {
                x=7;
                y=3;
            }
            else if(((Map[0][9]==Map[1][9]&&Map[1][9]==kr)||(Map[2][8]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[2][7])
            {
                x=8;
                y=3;
            }
            else if(((Map[0][8]==Map[1][9]&&Map[1][9]==kr)||(Map[2][8]==Map[2][9]&&Map[2][9]==kr)||(Map[0][10]==Map[1][10]&&Map[1][10]==kr))&&IsEmpty[2][8])
            {
                x=9;
                y=3;
            }
            else
            {
                do{
                x = (rand()%3)+7;
                y = (rand()%3)+1;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 8:
        do
        {
            if(((Map[4][9]==Map[4][10]&&Map[4][9]==Player1)||(Map[5][8]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][9]==Map[6][10]&&Map[5][10]==Player1))&&IsEmpty[3][6])
            {
                x=7;
                y=4;
            }
            else if(((Map[4][8]==Map[4][10]&&Map[4][8]==Player1)||(Map[5][9]==Map[6][9]&&Map[6][9]==Player1))&&IsEmpty[3][7])
            {
                x=8;
                y=4;
            }
            else if(((Map[4][8]==Map[4][9]&&Map[4][8]==Player1)||(Map[5][9]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][10]==Map[6][10]&&Map[6][10]==Player1))&&IsEmpty[3][8])
            {
                x=9;
                y=4;
            }
            else if(((Map[4][8]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][9]==Map[5][10]&&Map[5][10]==Player1))&&IsEmpty[4][6])
            {
                x=7;
                y=5;
            }
            else if(((Map[4][8]==Map[6][10]&&Map[4][8]==Player1)||(Map[6][8]==Map[4][10]&&Map[4][10]==Player1)||(Map[5][8]==Map[5][10]&&Map[5][10]==Player1)||(Map[4][9]==Map[6][9]&&Map[6][9]==Player1))&&IsEmpty[4][7])
            {
                x=8;
                y=5;
            }
            else if(((Map[5][8]==Map[5][9]&&Map[5][9]==Player1)||(Map[4][10]==Map[6][10]&&Map[4][10]==Player1))&&IsEmpty[4][8])
            {
                x=9;
                y=5;
            }
            else if(((Map[4][8]==Map[5][8]&&Map[4][8]==Player1)||(Map[6][9]==Map[6][10]&&Map[6][9]==Player1)||(Map[4][10]==Map[5][9]&&Map[5][9]==Player1))&&IsEmpty[5][6])
            {
                x=7;
                y=6;
            }
            else if(((Map[4][9]==Map[5][9]&&Map[5][9]==Player1)||(Map[6][8]==Map[6][10]&&Map[6][10]==Player1))&&IsEmpty[5][7])
            {
                x=8;
                y=6;
            }
            else if(((Map[4][8]==Map[5][9]&&Map[5][9]==Player1)||(Map[6][8]==Map[6][9]&&Map[6][9]==Player1)||(Map[4][10]==Map[5][10]&&Map[5][10]==Player1))&&IsEmpty[5][8])
            {
                x=9;
                y=6;
            }
            else             if(((Map[4][9]==Map[4][10]&&Map[4][9]==kr)||(Map[5][8]==Map[6][8]&&Map[6][8]==kr)||(Map[5][9]==Map[6][10]&&Map[5][10]==kr))&&IsEmpty[3][6])
            {
                x=7;
                y=4;
            }
            else if(((Map[4][8]==Map[4][10]&&Map[4][8]==kr)||(Map[5][9]==Map[6][9]&&Map[6][9]==kr))&&IsEmpty[3][7])
            {
                x=8;
                y=4;
            }
            else if(((Map[4][8]==Map[4][9]&&Map[4][8]==kr)||(Map[5][9]==Map[6][8]&&Map[6][8]==kr)||(Map[5][10]==Map[6][10]&&Map[6][10]==kr))&&IsEmpty[3][8])
            {
                x=9;
                y=4;
            }
            else if(((Map[4][8]==Map[6][8]&&Map[6][8]==kr)||(Map[5][9]==Map[5][10]&&Map[5][10]==kr))&&IsEmpty[4][6])
            {
                x=7;
                y=5;
            }
            else if(((Map[4][8]==Map[6][10]&&Map[4][8]==kr)||(Map[6][8]==Map[4][10]&&Map[4][10]==kr)||(Map[5][8]==Map[5][10]&&Map[5][10]==kr)||(Map[4][9]==Map[6][9]&&Map[6][9]==kr))&&IsEmpty[4][7])
            {
                x=8;
                y=5;
            }
            else if(((Map[5][8]==Map[5][9]&&Map[5][9]==kr)||(Map[4][10]==Map[6][10]&&Map[4][10]==kr))&&IsEmpty[4][8])
            {
                x=9;
                y=5;
            }
            else if(((Map[4][8]==Map[5][8]&&Map[4][8]==kr)||(Map[6][9]==Map[6][10]&&Map[6][9]==kr)||(Map[4][10]==Map[5][9]&&Map[5][9]==kr))&&IsEmpty[5][6])
            {
                x=7;
                y=6;
            }
            else if(((Map[4][9]==Map[5][9]&&Map[5][9]==kr)||(Map[6][8]==Map[6][10]&&Map[6][10]==kr))&&IsEmpty[5][7])
            {
                x=8;
                y=6;
            }
            else if(((Map[4][8]==Map[5][9]&&Map[5][9]==kr)||(Map[6][8]==Map[6][9]&&Map[6][9]==kr)||(Map[4][10]==Map[5][10]&&Map[5][10]==kr))&&IsEmpty[5][8])
            {
                x=9;
                y=6;
            }
            else
            {
                do{
                x = (rand()%3)+7;
                y = (rand()%3)+4;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 9:
        do
        {
            if(((Map[8][9]==Map[8][10]&&Map[8][9]==Player1)||(Map[9][8]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][9]==Map[10][10]&&Map[9][10]==Player1))&&IsEmpty[6][6])
            {
                x=7;
                y=7;
            }
            else if(((Map[8][8]==Map[8][10]&&Map[8][8]==Player1)||(Map[9][9]==Map[10][9]&&Map[10][9]==Player1))&&IsEmpty[6][7])
            {
                x=8;
                y=7;
            }
            else if(((Map[8][8]==Map[8][9]&&Map[8][8]==Player1)||(Map[9][9]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][10]==Map[10][10]&&Map[10][10]==Player1))&&IsEmpty[6][8])
            {
                x=9;
                y=7;
            }
            else if(((Map[8][8]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][9]==Map[9][10]&&Map[9][10]==Player1))&&IsEmpty[7][6])
            {
                x=7;
                y=8;
            }
            else if(((Map[8][8]==Map[10][10]&&Map[8][8]==Player1)||(Map[10][8]==Map[8][10]&&Map[8][10]==Player1)||(Map[9][8]==Map[9][10]&&Map[9][10]==Player1)||(Map[8][9]==Map[10][9]&&Map[10][9]==Player1))&&IsEmpty[7][7])
            {
                x=8;
                y=8;
            }
            else if(((Map[9][8]==Map[9][9]&&Map[9][9]==Player1)||(Map[8][10]==Map[10][10]&&Map[8][10]==Player1))&&IsEmpty[7][8])
            {
                x=9;
                y=8;
            }
            else if(((Map[8][8]==Map[9][8]&&Map[8][8]==Player1)||(Map[10][9]==Map[10][10]&&Map[10][9]==Player1)||(Map[8][10]==Map[8][9]&&Map[8][9]==Player1))&&IsEmpty[8][6])
            {
                x=7;
                y=9;
            }
            else if(((Map[8][9]==Map[9][9]&&Map[9][9]==Player1)||(Map[10][8]==Map[10][10]&&Map[10][10]==Player1))&&IsEmpty[8][7])
            {
                x=8;
                y=9;
            }
            else if(((Map[8][8]==Map[9][9]&&Map[9][9]==Player1)||(Map[10][8]==Map[10][9]&&Map[10][9]==Player1)||(Map[8][10]==Map[9][10]&&Map[9][10]==Player1))&&IsEmpty[8][8])
            {
                x=9;
                y=9;
            }
            else             if(((Map[8][9]==Map[8][10]&&Map[8][9]==kr)||(Map[9][8]==Map[10][8]&&Map[10][8]==kr)||(Map[9][9]==Map[10][10]&&Map[9][10]==kr))&&IsEmpty[6][6])
            {
                x=7;
                y=7;
            }
            else if(((Map[8][8]==Map[8][10]&&Map[8][8]==kr)||(Map[9][9]==Map[10][9]&&Map[10][9]==kr))&&IsEmpty[6][7])
            {
                x=8;
                y=7;
            }
            else if(((Map[8][8]==Map[8][9]&&Map[8][8]==kr)||(Map[9][9]==Map[10][8]&&Map[10][8]==kr)||(Map[9][10]==Map[10][10]&&Map[10][10]==kr))&&IsEmpty[6][8])
            {
                x=9;
                y=7;
            }
            else if(((Map[8][8]==Map[10][8]&&Map[10][8]==kr)||(Map[9][9]==Map[9][10]&&Map[9][10]==kr))&&IsEmpty[7][6])
            {
                x=7;
                y=8;
            }
            else if(((Map[8][8]==Map[10][10]&&Map[8][8]==kr)||(Map[10][8]==Map[8][10]&&Map[8][10]==kr)||(Map[9][8]==Map[9][10]&&Map[9][10]==kr)||(Map[8][9]==Map[10][9]&&Map[10][9]==kr))&&IsEmpty[7][7])
            {
                x=8;
                y=8;
            }
            else if(((Map[9][8]==Map[9][9]&&Map[9][9]==kr)||(Map[8][10]==Map[10][10]&&Map[8][10]==kr))&&IsEmpty[7][8])
            {
                x=9;
                y=8;
            }
            else if(((Map[8][8]==Map[9][8]&&Map[8][8]==kr)||(Map[10][9]==Map[10][10]&&Map[10][9]==kr)||(Map[8][10]==Map[8][9]&&Map[8][9]==kr))&&IsEmpty[8][6])
            {
                x=7;
                y=9;
            }
            else if(((Map[8][9]==Map[9][9]&&Map[9][9]==kr)||(Map[10][8]==Map[10][10]&&Map[10][10]==kr))&&IsEmpty[8][7])
            {
                x=8;
                y=9;
            }
            else if(((Map[8][8]==Map[9][9]&&Map[9][9]==kr)||(Map[10][8]==Map[10][9]&&Map[10][9]==kr)||(Map[8][10]==Map[9][10]&&Map[9][10]==kr))&&IsEmpty[8][8])
            {
                x=9;
                y=9;
            }
            else
            {
                do{
                x = (rand()%3)+7;
                y = (rand()%3)+7;
                                a = rand()%100+1;
                                }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>5);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    case 0:
        do
        {
            if((((Map[0][1]==Map[0][2]&&Map[0][2]==Player1)||(Map[1][0]==Map[2][0]&&Map[2][0]==Player1)||(Map[1][1]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[0][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=1;
            }
            else if((((Map[0][0]==Map[0][2]&&Map[0][0]==Player1)||(Map[1][1]==Map[2][1]&&Map[2][1]==Player1))&&IsEmpty[0][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=1;
            }
            else if((((Map[0][0]==Map[0][1]&&Map[0][1]==Player1)||(Map[1][1]==Map[2][0]&&Map[2][0]==Player1)||(Map[1][2]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[0][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=1;
            }
            else if((((Map[0][0]==Map[2][0]&&Map[0][0]==Player1)||(Map[1][1]==Map[1][2]&&Map[1][2]==Player1))&&IsEmpty[1][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=2;
            }
            else if((((Map[0][0]==Map[2][2]&&Map[0][0]==Player1)||(Map[2][0]==Map[0][2]&&Map[0][2]==Player1)||(Map[1][0]==Map[1][2]&&Map[1][2]==Player1)||(Map[0][1]==Map[2][1]&&Map[2][1]==Player1))&&IsEmpty[1][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=2;
            }
            else if((((Map[1][0]==Map[1][1]&&Map[1][1]==Player1)||(Map[0][2]==Map[2][2]&&Map[2][2]==Player1))&&IsEmpty[1][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=2;
            }
            else if((((Map[0][0]==Map[1][0]&&Map[1][0]==Player1)||(Map[2][1]==Map[2][2]&&Map[2][2]==Player1)||(Map[0][2]==Map[1][1]&&Map[1][1]==Player1))&&IsEmpty[2][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=3;
            }
            else if((((Map[0][1]==Map[1][1]&&Map[5][1]==Player1)||(Map[2][0]==Map[2][2]&&Map[2][0]==Player1))&&IsEmpty[2][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=3;
            }
            else if((((Map[0][0]==Map[1][1]&&Map[1][1]==Player1)||(Map[2][0]==Map[2][1]&&Map[2][0]==Player1)||(Map[0][2]==Map[1][2]&&Map[1][2]==Player1))&&IsEmpty[2][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=3;
            }
            else if((((Map[4][1]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][0]==Map[6][0]&&Map[5][0]==Player1)||(Map[5][1]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[3][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=4;
            }
            else if((((Map[4][0]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][1]==Map[6][1]&&Map[5][1]==Player1))&&IsEmpty[3][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=4;
            }
            else if((((Map[4][0]==Map[4][1]&&Map[4][1]==Player1)||(Map[5][1]==Map[6][0]&&Map[6][0]==Player1)||(Map[5][2]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[3][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=4;
            }
            else if((((Map[4][0]==Map[6][0]&&Map[4][0]==Player1)||(Map[5][1]==Map[5][2]&&Map[5][2]==Player1))&&IsEmpty[4][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=5;
            }
            else if((((Map[4][0]==Map[6][2]&&Map[4][0]==Player1)||(Map[6][0]==Map[4][2]&&Map[4][2]==Player1)||(Map[5][0]==Map[5][2]&&Map[5][2]==Player1)||(Map[4][1]==Map[6][1]&&Map[4][1]==Player1))&&IsEmpty[4][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=5;
            }
            else if((((Map[5][0]==Map[5][1]&&Map[5][1]==Player1)||(Map[4][2]==Map[6][2]&&Map[6][2]==Player1))&&IsEmpty[4][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=5;
            }
            else if((((Map[4][0]==Map[5][0]&&Map[5][0]==Player1)||(Map[6][1]==Map[6][2]&&Map[6][2]==Player1)||(Map[4][2]==Map[5][1]&&Map[5][1]==Player1))&&IsEmpty[5][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=6;
            }
            else if((((Map[4][1]==Map[5][1]&&Map[5][1]==Player1)||(Map[6][0]==Map[6][2]&&Map[6][0]==Player1))&&IsEmpty[5][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=6;
            }
            else if((((Map[4][0]==Map[5][1]&&Map[5][1]==Player1)||(Map[6][0]==Map[6][1]&&Map[6][0]==Player1)||(Map[4][2]==Map[5][2]&&Map[5][2]==Player1))&&IsEmpty[5][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=6;
            }
            else if((((Map[8][1]==Map[8][2]&&Map[7][2]==Player1)||(Map[9][0]==Map[10][0]&&Map[9][0]==Player1)||(Map[9][1]==Map[10][2]&&Map[10][2]==Player1))&&IsEmpty[6][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=7;
            }
            else if((((Map[8][0]==Map[8][2]&&Map[8][2]==Player1)||(Map[9][1]==Map[10][1]&&Map[10][1]==Player1))&&IsEmpty[6][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=7;
            }
            else if((((Map[8][0]==Map[8][1]&&Map[8][1]==Player1)||(Map[9][1]==Map[10][0]&&Map[10][0]==Player1)||(Map[9][2]==Map[10][2]&&Map[9][2]==Player1))&&IsEmpty[6][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=7;
            }
            else if((((Map[8][0]==Map[9][0]&&Map[9][0]==Player1)||(Map[9][1]==Map[9][2]&&Map[9][2]==Player1))&&IsEmpty[7][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=8;
            }
            else if((((Map[8][0]==Map[10][2]&&Map[8][0]==Player1)||(Map[10][0]==Map[8][2]&&Map[8][2]==Player1)||(Map[9][0]==Map[9][2]&&Map[9][2]==Player1)||(Map[8][1]==Map[10][1]&&Map[10][1]==Player1))&&IsEmpty[7][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=8;
            }
            else if((((Map[9][0]==Map[9][1]&&Map[9][1]==Player1)||(Map[8][2]==Map[10][2]&&Map[10][2]==Player1))&&IsEmpty[7][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=8;
            }
            else if((((Map[8][0]==Map[9][0]&&Map[9][0]==Player1)||(Map[10][1]==Map[10][2]&&Map[10][2]==Player1)||(Map[8][2]==Map[9][1]&&Map[9][1]==Player1))&&IsEmpty[8][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=9;
            }
            else if((((Map[8][1]==Map[9][1]&&Map[9][1]==Player1)||(Map[10][0]==Map[10][2]&&Map[10][0]==Player1))&&IsEmpty[8][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=9;
            }
            else if((((Map[10][0]==Map[10][1]&&Map[10][1]==Player1)||(Map[8][0]==Map[9][1]&&Map[9][1]==Player1)||(Map[8][2]==Map[9][2]&&Map[9][2]==Player1))&&IsEmpty[8][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=9;
            }
            else if((((Map[0][5]==Map[0][6]&&Map[0][5]==Player1)||(Map[1][4]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][5]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[0][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=1;
            }
            else if((((Map[0][4]==Map[0][6]&&Map[0][4]==Player1)||(Map[1][5]==Map[2][5]&&Map[2][5]==Player1))&&IsEmpty[0][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=1;
            }
            else if((((Map[0][4]==Map[0][5]&&Map[0][5]==Player1)||(Map[1][5]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][6]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[0][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=1;
            }
            else if((((Map[0][4]==Map[2][4]&&Map[2][4]==Player1)||(Map[1][5]==Map[1][6]&&Map[1][6]==Player1))&&IsEmpty[1][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=2;
            }
            else if((((Map[0][4]==Map[2][6]&&Map[0][4]==Player1)||(Map[2][4]==Map[0][6]&&Map[0][6]==Player1)||(Map[1][4]==Map[1][6]&&Map[1][6]==Player1)||(Map[0][5]==Map[2][5]&&Map[2][5]==Player1))&&IsEmpty[1][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=2;
            }
            else if((((Map[1][4]==Map[1][5]&&Map[1][5]==Player1)||(Map[0][6]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[1][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=2;
            }
            else if((((Map[0][4]==Map[1][4]&&Map[1][4]==Player1)||(Map[2][5]==Map[2][6]&&Map[2][5]==Player1)||(Map[0][6]==Map[1][5]&&Map[1][5]==Player1))&&IsEmpty[2][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=3;
            }
            else if((((Map[0][5]==Map[1][5]&&Map[1][5]==Player1)||(Map[2][4]==Map[2][6]&&Map[2][6]==Player1))&&IsEmpty[2][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=3;
            }
            else if((((Map[0][4]==Map[1][5]&&Map[1][5]==Player1)||(Map[2][4]==Map[2][5]&&Map[2][5]==Player1)||(Map[0][6]==Map[1][6]&&Map[1][6]==Player1))&&IsEmpty[2][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=3;
            }
            else if((((Map[4][5]==Map[4][6]&&Map[4][5]==Player1)||(Map[5][4]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][5]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[3][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=4;
            }
            else if((((Map[4][4]==Map[4][6]&&Map[4][4]==Player1)||(Map[5][5]==Map[6][5]&&Map[6][5]==Player1))&&IsEmpty[3][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=4;
            }
            else if((((Map[4][4]==Map[4][5]&&Map[4][5]==Player1)||(Map[5][5]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][6]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[3][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=4;
            }
            else if((((Map[4][4]==Map[6][4]&&Map[6][4]==Player1)||(Map[5][5]==Map[5][6]&&Map[5][6]==Player1))&&IsEmpty[4][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=5;
            }
            else if((((Map[4][4]==Map[6][6]&&Map[4][4]==Player1)||(Map[6][4]==Map[5][6]&&Map[5][6]==Player1)||(Map[5][4]==Map[5][6]&&Map[5][6]==Player1)||(Map[4][5]==Map[6][5]&&Map[5][5]==Player1))&&IsEmpty[4][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=5;
            }
            else if((((Map[5][4]==Map[5][5]&&Map[5][5]==Player1)||(Map[4][6]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[4][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=5;
            }
            else if((((Map[4][4]==Map[5][4]&&Map[4][4]==Player1)||(Map[6][5]==Map[6][6]&&Map[6][6]==Player1)||(Map[4][6]==Map[5][5]&&Map[5][5]==Player1))&&IsEmpty[5][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=6;
            }
            else if((((Map[4][5]==Map[5][5]&&Map[5][5]==Player1)||(Map[6][4]==Map[6][6]&&Map[6][6]==Player1))&&IsEmpty[5][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=6;
            }
            else if((((Map[4][4]==Map[5][5]&&Map[5][5]==Player1)||(Map[6][4]==Map[6][5]&&Map[2][5]==Player1)||(Map[4][6]==Map[5][6]&&Map[5][6]==Player1))&&IsEmpty[5][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=6;
            }
            else if((((Map[8][5]==Map[8][6]&&Map[8][5]==Player1)||(Map[8][4]==Map[9][4]&&Map[9][4]==Player1)||(Map[9][5]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[6][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=7;
            }
            else if((((Map[8][4]==Map[8][6]&&Map[8][4]==Player1)||(Map[9][5]==Map[10][5]&&Map[10][5]==Player1))&&IsEmpty[6][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=7;
            }
            else if((((Map[8][4]==Map[8][5]&&Map[8][5]==Player1)||(Map[9][5]==Map[10][4]&&Map[10][4]==Player1)||(Map[9][6]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[6][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=7;
            }
            else if((((Map[8][4]==Map[10][4]&&Map[10][4]==Player1)||(Map[9][5]==Map[9][6]&&Map[9][6]==Player1))&&IsEmpty[7][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=8;
            }
            else if((((Map[8][4]==Map[10][6]&&Map[8][4]==Player1)||(Map[10][4]==Map[9][6]&&Map[9][6]==Player1)||(Map[9][4]==Map[9][6]&&Map[9][6]==Player1)||(Map[8][5]==Map[10][5]&&Map[5][5]==Player1))&&IsEmpty[7][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=8;
            }
            else if((((Map[9][4]==Map[9][5]&&Map[9][5]==Player1)||(Map[8][6]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[7][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=8;
            }
            else if((((Map[8][4]==Map[9][4]&&Map[9][4]==Player1)||(Map[10][5]==Map[10][6]&&Map[10][6]==Player1)||(Map[8][6]==Map[9][5]&&Map[9][5]==Player1))&&IsEmpty[8][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=9;
            }
            else if((((Map[8][5]==Map[9][5]&&Map[9][5]==Player1)||(Map[10][4]==Map[10][6]&&Map[10][6]==Player1))&&IsEmpty[8][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=9;
            }
            else if((((Map[8][4]==Map[9][5]&&Map[9][5]==Player1)||(Map[10][4]==Map[10][5]&&Map[10][5]==Player1)||(Map[8][6]==Map[9][6]&&Map[9][6]==Player1))&&IsEmpty[8][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=9;
            }
            else if((((Map[0][9]==Map[0][10]&&Map[0][9]==Player1)||(Map[1][8]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][9]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[0][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=1;
            }
            else if((((Map[0][8]==Map[0][10]&&Map[0][8]==Player1)||(Map[1][9]==Map[2][9]&&Map[2][9]==Player1))&&IsEmpty[0][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=1;
            }
            else if((((Map[0][8]==Map[0][9]&&Map[0][8]==Player1)||(Map[1][9]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][10]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[0][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=1;
            }
            else if((((Map[0][8]==Map[2][8]&&Map[2][8]==Player1)||(Map[1][9]==Map[1][10]&&Map[1][10]==Player1))&&IsEmpty[1][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=2;
            }
            else if((((Map[0][8]==Map[2][10]&&Map[0][8]==Player1)||(Map[2][8]==Map[0][10]&&Map[0][10]==Player1)||(Map[1][8]==Map[1][10]&&Map[1][10]==Player1)||(Map[0][9]==Map[2][9]&&Map[2][9]==Player1))&&IsEmpty[1][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=2;
            }
            else if((((Map[1][8]==Map[1][9]&&Map[1][9]==Player1)||(Map[0][10]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[1][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=2;
            }
            else if((((Map[0][8]==Map[1][8]&&Map[1][8]==Player1)||(Map[2][9]==Map[2][10]&&Map[2][9]==Player1)||(Map[0][10]==Map[1][9]&&Map[1][9]==Player1))&&IsEmpty[2][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=3;
            }
            else if((((Map[0][9]==Map[1][9]&&Map[1][9]==Player1)||(Map[2][8]==Map[2][10]&&Map[2][10]==Player1))&&IsEmpty[2][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=3;
            }
            else if((((Map[0][8]==Map[1][9]&&Map[1][9]==Player1)||(Map[2][8]==Map[2][9]&&Map[2][9]==Player1)||(Map[0][10]==Map[1][10]&&Map[1][10]==Player1))&&IsEmpty[2][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=3;
            }
            else if((((Map[4][9]==Map[4][10]&&Map[4][9]==Player1)||(Map[5][8]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][9]==Map[6][10]&&Map[5][10]==Player1))&&IsEmpty[3][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=4;
            }
            else if((((Map[4][8]==Map[4][10]&&Map[4][8]==Player1)||(Map[5][9]==Map[6][9]&&Map[6][9]==Player1))&&IsEmpty[3][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=4;
            }
            else if((((Map[4][8]==Map[4][9]&&Map[4][8]==Player1)||(Map[5][9]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][10]==Map[6][10]&&Map[6][10]==Player1))&&IsEmpty[3][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=4;
            }
            else if((((Map[4][8]==Map[6][8]&&Map[6][8]==Player1)||(Map[5][9]==Map[5][10]&&Map[5][10]==Player1))&&IsEmpty[4][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=5;
            }
            else if((((Map[4][8]==Map[6][10]&&Map[4][8]==Player1)||(Map[6][8]==Map[4][10]&&Map[4][10]==Player1)||(Map[5][8]==Map[5][10]&&Map[5][10]==Player1)||(Map[4][9]==Map[6][9]&&Map[6][9]==Player1))&&IsEmpty[4][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=5;
            }
            else if((((Map[5][8]==Map[5][9]&&Map[5][9]==Player1)||(Map[4][10]==Map[6][10]&&Map[4][10]==Player1))&&IsEmpty[4][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=5;
            }
            else if((((Map[4][8]==Map[5][8]&&Map[4][8]==Player1)||(Map[6][9]==Map[6][10]&&Map[6][9]==Player1)||(Map[4][10]==Map[4][9]&&Map[4][9]==Player1))&&IsEmpty[5][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=6;
            }
            else if((((Map[4][9]==Map[5][9]&&Map[5][9]==Player1)||(Map[6][8]==Map[6][10]&&Map[6][10]==Player1))&&IsEmpty[5][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=6;
            }
            else if((((Map[4][8]==Map[5][9]&&Map[5][9]==Player1)||(Map[6][8]==Map[6][9]&&Map[6][9]==Player1)||(Map[4][10]==Map[5][10]&&Map[5][10]==Player1))&&IsEmpty[5][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=6;
            }
            else if((((Map[8][9]==Map[8][10]&&Map[8][9]==Player1)||(Map[9][8]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][9]==Map[10][10]&&Map[9][10]==Player1))&&IsEmpty[6][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=7;
            }
            else if((((Map[8][8]==Map[8][10]&&Map[8][8]==Player1)||(Map[9][9]==Map[10][9]&&Map[10][9]==Player1))&&IsEmpty[6][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=7;
            }
            else if((((Map[8][8]==Map[8][9]&&Map[8][8]==Player1)||(Map[9][9]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][10]==Map[10][10]&&Map[10][10]==Player1))&&IsEmpty[6][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=7;
            }
            else if((((Map[8][8]==Map[10][8]&&Map[10][8]==Player1)||(Map[9][9]==Map[9][10]&&Map[9][10]==Player1))&&IsEmpty[7][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=8;
            }
            else if((((Map[8][8]==Map[10][10]&&Map[8][8]==Player1)||(Map[10][8]==Map[8][10]&&Map[8][10]==Player1)||(Map[9][8]==Map[9][10]&&Map[9][10]==Player1)||(Map[8][9]==Map[10][9]&&Map[10][9]==Player1))&&IsEmpty[7][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=8;
            }
            else if((((Map[9][8]==Map[9][9]&&Map[9][9]==Player1)||(Map[8][10]==Map[10][10]&&Map[8][10]==Player1))&&IsEmpty[7][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=8;
            }
            else if((((Map[8][8]==Map[9][8]&&Map[8][8]==Player1)||(Map[10][9]==Map[10][10]&&Map[10][9]==Player1)||(Map[8][10]==Map[8][9]&&Map[8][9]==Player1))&&IsEmpty[8][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=9;
            }
            else if((((Map[8][9]==Map[9][9]&&Map[9][9]==Player1)||(Map[10][8]==Map[10][10]&&Map[10][10]==Player1))&&IsEmpty[8][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=9;
            }
            else if((((Map[8][8]==Map[9][9]&&Map[9][9]==Player1)||(Map[10][8]==Map[10][9]&&Map[10][9]==Player1)||(Map[8][10]==Map[9][10]&&Map[9][10]==Player1))&&IsEmpty[8][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=9;
            }
            else             if((((Map[0][1]==Map[0][2]&&Map[0][2]==kr)||(Map[1][0]==Map[2][0]&&Map[2][0]==kr)||(Map[1][1]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[0][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=1;
            }
            else if((((Map[0][0]==Map[0][2]&&Map[0][0]==kr)||(Map[1][1]==Map[2][1]&&Map[2][1]==kr))&&IsEmpty[0][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=1;
            }
            else if((((Map[0][0]==Map[0][1]&&Map[0][1]==kr)||(Map[1][1]==Map[2][0]&&Map[2][0]==kr)||(Map[1][2]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[0][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=1;
            }
            else if((((Map[0][0]==Map[2][0]&&Map[0][0]==kr)||(Map[1][1]==Map[1][2]&&Map[1][2]==kr))&&IsEmpty[1][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=2;
            }
            else if((((Map[0][0]==Map[2][2]&&Map[0][0]==kr)||(Map[2][0]==Map[0][2]&&Map[0][2]==kr)||(Map[1][0]==Map[1][2]&&Map[1][2]==kr)||(Map[0][1]==Map[2][1]&&Map[2][1]==kr))&&IsEmpty[1][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=2;
            }
            else if((((Map[1][0]==Map[1][1]&&Map[1][1]==kr)||(Map[0][2]==Map[2][2]&&Map[2][2]==kr))&&IsEmpty[1][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=2;
            }
            else if((((Map[0][0]==Map[1][0]&&Map[1][0]==kr)||(Map[2][1]==Map[2][2]&&Map[2][2]==kr)||(Map[0][2]==Map[1][1]&&Map[1][1]==kr))&&IsEmpty[2][0])&&(OO[0]==false&&XX[0]==false))
            {
                x=1;
                y=3;
            }
            else if((((Map[0][1]==Map[1][1]&&Map[5][1]==kr)||(Map[2][0]==Map[2][2]&&Map[2][0]==kr))&&IsEmpty[2][1])&&(OO[0]==false&&XX[0]==false))
            {
                x=2;
                y=3;
            }
            else if((((Map[0][0]==Map[1][1]&&Map[1][1]==kr)||(Map[2][0]==Map[2][1]&&Map[2][0]==kr)||(Map[0][2]==Map[1][2]&&Map[1][2]==kr))&&IsEmpty[2][2])&&(OO[0]==false&&XX[0]==false))
            {
                x=3;
                y=3;
            }
            else if((((Map[4][1]==Map[4][2]&&Map[4][2]==kr)||(Map[5][0]==Map[6][0]&&Map[5][0]==kr)||(Map[5][1]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[3][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=4;
            }
            else if((((Map[4][0]==Map[4][2]&&Map[4][2]==kr)||(Map[5][1]==Map[6][1]&&Map[5][1]==kr))&&IsEmpty[3][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=4;
            }
            else if((((Map[4][0]==Map[4][1]&&Map[4][1]==kr)||(Map[5][1]==Map[6][0]&&Map[6][0]==kr)||(Map[5][2]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[3][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=4;
            }
            else if((((Map[4][0]==Map[6][0]&&Map[4][0]==kr)||(Map[5][1]==Map[5][2]&&Map[5][2]==kr))&&IsEmpty[4][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=5;
            }
            else if((((Map[4][0]==Map[6][2]&&Map[4][0]==kr)||(Map[6][0]==Map[4][2]&&Map[4][2]==kr)||(Map[5][0]==Map[5][2]&&Map[5][2]==kr)||(Map[4][1]==Map[6][1]&&Map[4][1]==kr))&&IsEmpty[4][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=5;
            }
            else if((((Map[5][0]==Map[5][1]&&Map[5][1]==kr)||(Map[4][2]==Map[6][2]&&Map[6][2]==kr))&&IsEmpty[4][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=5;
            }
            else if((((Map[4][0]==Map[5][0]&&Map[5][0]==kr)||(Map[6][1]==Map[6][2]&&Map[6][2]==kr)||(Map[4][2]==Map[5][1]&&Map[5][1]==kr))&&IsEmpty[5][0])&&(OO[1]==false&&XX[1]==false))
            {
                x=1;
                y=6;
            }
            else if((((Map[4][1]==Map[5][1]&&Map[5][1]==kr)||(Map[6][0]==Map[6][2]&&Map[6][0]==kr))&&IsEmpty[5][1])&&(OO[1]==false&&XX[1]==false))
            {
                x=2;
                y=6;
            }
            else if((((Map[4][0]==Map[5][1]&&Map[5][1]==kr)||(Map[6][0]==Map[6][1]&&Map[6][0]==kr)||(Map[4][2]==Map[5][2]&&Map[5][2]==kr))&&IsEmpty[5][2])&&(OO[1]==false&&XX[1]==false))
            {
                x=3;
                y=6;
            }
            else if((((Map[8][1]==Map[8][2]&&Map[7][2]==kr)||(Map[9][0]==Map[10][0]&&Map[9][0]==kr)||(Map[9][1]==Map[10][2]&&Map[10][2]==kr))&&IsEmpty[6][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=7;
            }
            else if((((Map[8][0]==Map[8][2]&&Map[8][2]==kr)||(Map[9][1]==Map[10][1]&&Map[10][1]==kr))&&IsEmpty[6][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=7;
            }
            else if((((Map[8][0]==Map[8][1]&&Map[8][1]==kr)||(Map[9][1]==Map[10][0]&&Map[10][0]==kr)||(Map[9][2]==Map[10][2]&&Map[9][2]==kr))&&IsEmpty[6][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=7;
            }
            else if((((Map[8][0]==Map[9][0]&&Map[9][0]==kr)||(Map[9][1]==Map[9][2]&&Map[9][2]==kr))&&IsEmpty[7][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=8;
            }
            else if((((Map[8][0]==Map[10][2]&&Map[8][0]==kr)||(Map[10][0]==Map[8][2]&&Map[8][2]==kr)||(Map[9][0]==Map[9][2]&&Map[9][2]==kr)||(Map[8][1]==Map[10][1]&&Map[10][1]==kr))&&IsEmpty[7][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=8;
            }
            else if((((Map[9][0]==Map[9][1]&&Map[9][1]==kr)||(Map[8][2]==Map[10][2]&&Map[10][2]==kr))&&IsEmpty[7][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=8;
            }
            else if((((Map[8][0]==Map[9][0]&&Map[9][0]==kr)||(Map[10][1]==Map[10][2]&&Map[10][2]==kr)||(Map[8][2]==Map[9][1]&&Map[9][1]==kr))&&IsEmpty[8][0])&&(OO[2]==false&&XX[2]==false))
            {
                x=1;
                y=9;
            }
            else if((((Map[8][1]==Map[9][1]&&Map[9][1]==kr)||(Map[10][0]==Map[10][2]&&Map[10][0]==kr))&&IsEmpty[8][1])&&(OO[2]==false&&XX[2]==false))
            {
                x=2;
                y=9;
            }
            else if((((Map[10][0]==Map[10][1]&&Map[10][1]==kr)||(Map[8][0]==Map[9][1]&&Map[9][1]==kr)||(Map[8][2]==Map[9][2]&&Map[9][2]==kr))&&IsEmpty[8][2])&&(OO[2]==false&&XX[2]==false))
            {
                x=3;
                y=9;
            }
            else if((((Map[0][5]==Map[0][6]&&Map[0][5]==kr)||(Map[1][4]==Map[2][4]&&Map[2][4]==kr)||(Map[1][5]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[0][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=1;
            }
            else if((((Map[0][4]==Map[0][6]&&Map[0][4]==kr)||(Map[1][5]==Map[2][5]&&Map[2][5]==kr))&&IsEmpty[0][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=1;
            }
            else if((((Map[0][4]==Map[0][5]&&Map[0][5]==kr)||(Map[1][5]==Map[2][4]&&Map[2][4]==kr)||(Map[1][6]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[0][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=1;
            }
            else if((((Map[0][4]==Map[2][4]&&Map[2][4]==kr)||(Map[1][5]==Map[1][6]&&Map[1][6]==kr))&&IsEmpty[1][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=2;
            }
            else if((((Map[0][4]==Map[2][6]&&Map[0][4]==kr)||(Map[2][4]==Map[0][6]&&Map[0][6]==kr)||(Map[1][4]==Map[1][6]&&Map[1][6]==kr)||(Map[0][5]==Map[2][5]&&Map[2][5]==kr))&&IsEmpty[1][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=2;
            }
            else if((((Map[1][4]==Map[1][5]&&Map[1][5]==kr)||(Map[0][6]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[1][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=2;
            }
            else if((((Map[0][4]==Map[1][4]&&Map[1][4]==kr)||(Map[2][5]==Map[2][6]&&Map[2][5]==kr)||(Map[0][6]==Map[1][5]&&Map[1][5]==kr))&&IsEmpty[2][3])&&(OO[3]==false&&XX[3]==false))
            {
                x=4;
                y=3;
            }
            else if((((Map[0][5]==Map[1][5]&&Map[1][5]==kr)||(Map[2][4]==Map[2][6]&&Map[2][6]==kr))&&IsEmpty[2][4])&&(OO[3]==false&&XX[3]==false))
            {
                x=5;
                y=3;
            }
            else if((((Map[0][4]==Map[1][5]&&Map[1][5]==kr)||(Map[2][4]==Map[2][5]&&Map[2][5]==kr)||(Map[0][6]==Map[1][6]&&Map[1][6]==kr))&&IsEmpty[2][5])&&(OO[3]==false&&XX[3]==false))
            {
                x=6;
                y=3;
            }
            else if((((Map[4][5]==Map[4][6]&&Map[4][5]==kr)||(Map[5][4]==Map[6][4]&&Map[6][4]==kr)||(Map[5][5]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[3][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=4;
            }
            else if((((Map[4][4]==Map[4][6]&&Map[4][4]==kr)||(Map[5][5]==Map[6][5]&&Map[6][5]==kr))&&IsEmpty[3][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=4;
            }
            else if((((Map[4][4]==Map[4][5]&&Map[4][5]==kr)||(Map[5][5]==Map[6][4]&&Map[6][4]==kr)||(Map[5][6]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[3][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=4;
            }
            else if((((Map[4][4]==Map[6][4]&&Map[6][4]==kr)||(Map[5][5]==Map[5][6]&&Map[5][6]==kr))&&IsEmpty[4][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=5;
            }
            else if((((Map[4][4]==Map[6][6]&&Map[4][4]==kr)||(Map[6][4]==Map[5][6]&&Map[5][6]==kr)||(Map[5][4]==Map[5][6]&&Map[5][6]==kr)||(Map[4][5]==Map[6][5]&&Map[5][5]==kr))&&IsEmpty[4][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=5;
            }
            else if((((Map[5][4]==Map[5][5]&&Map[5][5]==kr)||(Map[4][6]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[4][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=5;
            }
            else if((((Map[4][4]==Map[5][4]&&Map[4][4]==kr)||(Map[6][5]==Map[6][6]&&Map[6][6]==kr)||(Map[4][6]==Map[5][5]&&Map[5][5]==kr))&&IsEmpty[5][3])&&(OO[4]==false&&XX[4]==false))
            {
                x=4;
                y=6;
            }
            else if((((Map[4][5]==Map[5][5]&&Map[5][5]==kr)||(Map[6][4]==Map[6][6]&&Map[6][6]==kr))&&IsEmpty[5][4])&&(OO[4]==false&&XX[4]==false))
            {
                x=5;
                y=6;
            }
            else if((((Map[4][4]==Map[5][5]&&Map[5][5]==kr)||(Map[6][4]==Map[6][5]&&Map[2][5]==kr)||(Map[4][6]==Map[5][6]&&Map[5][6]==kr))&&IsEmpty[5][5])&&(OO[4]==false&&XX[4]==false))
            {
                x=6;
                y=6;
            }
            else if((((Map[8][5]==Map[8][6]&&Map[8][5]==kr)||(Map[8][4]==Map[9][4]&&Map[9][4]==kr)||(Map[9][5]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[6][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=7;
            }
            else if((((Map[8][4]==Map[8][6]&&Map[8][4]==kr)||(Map[9][5]==Map[10][5]&&Map[10][5]==kr))&&IsEmpty[6][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=7;
            }
            else if((((Map[8][4]==Map[8][5]&&Map[8][5]==kr)||(Map[9][5]==Map[10][4]&&Map[10][4]==kr)||(Map[9][6]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[6][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=7;
            }
            else if((((Map[8][4]==Map[10][4]&&Map[10][4]==kr)||(Map[9][5]==Map[9][6]&&Map[9][6]==kr))&&IsEmpty[7][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=8;
            }
            else if((((Map[8][4]==Map[10][6]&&Map[8][4]==kr)||(Map[10][4]==Map[9][6]&&Map[9][6]==kr)||(Map[9][4]==Map[9][6]&&Map[9][6]==kr)||(Map[8][5]==Map[10][5]&&Map[5][5]==kr))&&IsEmpty[7][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=8;
            }
            else if((((Map[9][4]==Map[9][5]&&Map[9][5]==kr)||(Map[8][6]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[7][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=8;
            }
            else if((((Map[8][4]==Map[9][4]&&Map[9][4]==kr)||(Map[10][5]==Map[10][6]&&Map[10][6]==kr)||(Map[8][6]==Map[9][5]&&Map[9][5]==kr))&&IsEmpty[8][3])&&(OO[5]==false&&XX[5]==false))
            {
                x=4;
                y=9;
            }
            else if((((Map[8][5]==Map[9][5]&&Map[9][5]==kr)||(Map[10][4]==Map[10][6]&&Map[10][6]==kr))&&IsEmpty[8][4])&&(OO[5]==false&&XX[5]==false))
            {
                x=5;
                y=9;
            }
            else if((((Map[8][4]==Map[9][5]&&Map[9][5]==kr)||(Map[10][4]==Map[10][5]&&Map[10][5]==kr)||(Map[8][6]==Map[9][6]&&Map[9][6]==kr))&&IsEmpty[8][5])&&(OO[5]==false&&XX[5]==false))
            {
                x=6;
                y=9;
            }
            else if((((Map[0][9]==Map[0][10]&&Map[0][9]==kr)||(Map[1][8]==Map[2][8]&&Map[2][8]==kr)||(Map[1][9]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[0][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=1;
            }
            else if((((Map[0][8]==Map[0][10]&&Map[0][8]==kr)||(Map[1][9]==Map[2][9]&&Map[2][9]==kr))&&IsEmpty[0][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=1;
            }
            else if((((Map[0][8]==Map[0][9]&&Map[0][8]==kr)||(Map[1][9]==Map[2][8]&&Map[2][8]==kr)||(Map[1][10]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[0][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=1;
            }
            else if((((Map[0][8]==Map[2][8]&&Map[2][8]==kr)||(Map[1][9]==Map[1][10]&&Map[1][10]==kr))&&IsEmpty[1][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=2;
            }
            else if((((Map[0][8]==Map[2][10]&&Map[0][8]==kr)||(Map[2][8]==Map[0][10]&&Map[0][10]==kr)||(Map[1][8]==Map[1][10]&&Map[1][10]==kr)||(Map[0][9]==Map[2][9]&&Map[2][9]==kr))&&IsEmpty[1][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=2;
            }
            else if((((Map[1][8]==Map[1][9]&&Map[1][9]==kr)||(Map[0][10]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[1][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=2;
            }
            else if((((Map[0][8]==Map[1][8]&&Map[1][8]==kr)||(Map[2][9]==Map[2][10]&&Map[2][9]==kr)||(Map[0][10]==Map[1][9]&&Map[1][9]==kr))&&IsEmpty[2][6])&&(OO[6]==false&&XX[6]==false))
            {
                x=7;
                y=3;
            }
            else if((((Map[0][9]==Map[1][9]&&Map[1][9]==kr)||(Map[2][8]==Map[2][10]&&Map[2][10]==kr))&&IsEmpty[2][7])&&(OO[6]==false&&XX[6]==false))
            {
                x=8;
                y=3;
            }
            else if((((Map[0][8]==Map[1][9]&&Map[1][9]==kr)||(Map[2][8]==Map[2][9]&&Map[2][9]==kr)||(Map[0][10]==Map[1][10]&&Map[1][10]==kr))&&IsEmpty[2][8])&&(OO[6]==false&&XX[6]==false))
            {
                x=9;
                y=3;
            }
            else if((((Map[4][9]==Map[4][10]&&Map[4][9]==kr)||(Map[5][8]==Map[6][8]&&Map[6][8]==kr)||(Map[5][9]==Map[6][10]&&Map[5][10]==kr))&&IsEmpty[3][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=4;
            }
            else if((((Map[4][8]==Map[4][10]&&Map[4][8]==kr)||(Map[5][9]==Map[6][9]&&Map[6][9]==kr))&&IsEmpty[3][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=4;
            }
            else if((((Map[4][8]==Map[4][9]&&Map[4][8]==kr)||(Map[5][9]==Map[6][8]&&Map[6][8]==kr)||(Map[5][10]==Map[6][10]&&Map[6][10]==kr))&&IsEmpty[3][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=4;
            }
            else if((((Map[4][8]==Map[6][8]&&Map[6][8]==kr)||(Map[5][9]==Map[5][10]&&Map[5][10]==kr))&&IsEmpty[4][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=5;
            }
            else if((((Map[4][8]==Map[6][10]&&Map[4][8]==kr)||(Map[6][8]==Map[4][10]&&Map[4][10]==kr)||(Map[5][8]==Map[5][10]&&Map[5][10]==kr)||(Map[4][9]==Map[6][9]&&Map[6][9]==kr))&&IsEmpty[4][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=5;
            }
            else if((((Map[5][8]==Map[5][9]&&Map[5][9]==kr)||(Map[4][10]==Map[6][10]&&Map[4][10]==kr))&&IsEmpty[4][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=5;
            }
            else if((((Map[4][8]==Map[5][8]&&Map[4][8]==kr)||(Map[6][9]==Map[6][10]&&Map[6][9]==kr)||(Map[4][10]==Map[4][9]&&Map[4][9]==kr))&&IsEmpty[5][6])&&(OO[7]==false&&XX[7]==false))
            {
                x=7;
                y=6;
            }
            else if((((Map[4][9]==Map[5][9]&&Map[5][9]==kr)||(Map[6][8]==Map[6][10]&&Map[6][10]==kr))&&IsEmpty[5][7])&&(OO[7]==false&&XX[7]==false))
            {
                x=8;
                y=6;
            }
            else if((((Map[4][8]==Map[5][9]&&Map[5][9]==kr)||(Map[6][8]==Map[6][9]&&Map[6][9]==kr)||(Map[4][10]==Map[5][10]&&Map[5][10]==kr))&&IsEmpty[5][8])&&(OO[7]==false&&XX[7]==false))
            {
                x=9;
                y=6;
            }
            else if((((Map[8][9]==Map[8][10]&&Map[8][9]==kr)||(Map[9][8]==Map[10][8]&&Map[10][8]==kr)||(Map[9][9]==Map[10][10]&&Map[9][10]==kr))&&IsEmpty[6][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=7;
            }
            else if((((Map[8][8]==Map[8][10]&&Map[8][8]==kr)||(Map[9][9]==Map[10][9]&&Map[10][9]==kr))&&IsEmpty[6][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=7;
            }
            else if((((Map[8][8]==Map[8][9]&&Map[8][8]==kr)||(Map[9][9]==Map[10][8]&&Map[10][8]==kr)||(Map[9][10]==Map[10][10]&&Map[10][10]==kr))&&IsEmpty[6][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=7;
            }
            else if((((Map[8][8]==Map[10][8]&&Map[10][8]==kr)||(Map[9][9]==Map[9][10]&&Map[9][10]==kr))&&IsEmpty[7][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=8;
            }
            else if((((Map[8][8]==Map[10][10]&&Map[8][8]==kr)||(Map[10][8]==Map[8][10]&&Map[8][10]==kr)||(Map[9][8]==Map[9][10]&&Map[9][10]==kr)||(Map[8][9]==Map[10][9]&&Map[10][9]==kr))&&IsEmpty[7][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=8;
            }
            else if((((Map[9][8]==Map[9][9]&&Map[9][9]==kr)||(Map[8][10]==Map[10][10]&&Map[8][10]==kr))&&IsEmpty[7][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=8;
            }
            else if((((Map[8][8]==Map[9][8]&&Map[8][8]==kr)||(Map[10][9]==Map[10][10]&&Map[10][9]==kr)||(Map[8][10]==Map[8][9]&&Map[8][9]==kr))&&IsEmpty[8][6])&&(OO[8]==false&&XX[8]==false))
            {
                x=7;
                y=9;
            }
            else if((((Map[8][9]==Map[9][9]&&Map[9][9]==kr)||(Map[10][8]==Map[10][10]&&Map[10][10]==kr))&&IsEmpty[8][7])&&(OO[8]==false&&XX[8]==false))
            {
                x=8;
                y=9;
            }
            else if((((Map[8][8]==Map[9][9]&&Map[9][9]==kr)||(Map[10][8]==Map[10][9]&&Map[10][9]==kr)||(Map[8][10]==Map[9][10]&&Map[9][10]==kr))&&IsEmpty[8][8])&&(OO[8]==false&&XX[8]==false))
            {
                x=9;
                y=9;
            }
            else
            {
                do
                {
                x = (rand()%9)+1;
                y = (rand()%9)+1;
                                                a = rand()%100+1;
                            }while((OO[NextPrzedzial(y,x)]==true||XX[NextPrzedzial(y,x)])||a>4);
            }
        }
        while(IsEmpty[y-1][x-1]==false||(OO[Przedzial(x,y)]==true||XX[Przedzial(x,y)]==true));
        break;
    }
    IsEmpty[y-1][x-1] = false;
    if(y<=3&&x<=3)
        Map[y-1][x-1] = kr;
    else if(y<=6&&x<=3)
        Map[y][x-1] = kr;
    else if(y<=9&&x<=3)
        Map[y+1][x-1] = kr;
    else if(x<=6&&y<=3)
        Map[y-1][x] = kr;
    else if(x<=9&&y<=3)
        Map[y-1][x+1] = kr;
    else if(x<=6&&y<=6)
        Map[y][x] = kr;
    else if(x<=6&&y<=9)
        Map[y+1][x] = kr;
    else if(x<=9&&y<=6)
        Map[y][x+1] = kr;
    else
        Map[y+1][x+1] = kr;
    if(kr==Player2)
        UpdateMap(Player2);
    else if(kr==Player1)
        UpdateMap(Player1);
    ChangePlace(y,x);
}
void Mapa::Reset()
{
    int i,j;
    for(i = 0; i<MAP_SIZE; i++)
        for(j = 0; j<MAP_SIZE2; j++)
        {
            if(i==3||i==7)
            {
                Map[i][j] = ' ';
            }
            else if((j==3||j==7)&&(i!=3||i!=7))
                Map[i][j] = '\t';
            else
                Map[i][j] = MAP;
            Map[i][MAP_SIZE2-1] = '\n';
        }
    for(i=0; i<MAP_SIZE; i++)
        for(j=0; j<MAP_SIZE2; j++)
            IsEmpty[i][j]=true;
    for(i=0; i<9; i++)
        OO[i]=XX[i]=false;
    CurrentPlace=0;
    WIN=false;
}
void Mapa::Ruch(const char kr)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout<<"Gracz: ";
    if(kr==Player1)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    else
        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout<<kr<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    int x,y;
    x = y = 0;
    int wyznacznik;
    if(CurrentPlace==0)
    {
        do
        {
            char g;
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                x = Wprowadz();
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    g = getch();
                    g-=48;
                    if(g==-40)break;
                }
                while(g>9||g<1);
                if(g==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(kr==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<kr<<endl;
                }
            }
            while(g==-40);
            y=g;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            if((OO[wyznacznik]==true||XX[wyznacznik]==true)||IsEmpty[y-1][x-1]==false)
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
    }
    else
    {
        switch(CurrentPlace)
        {
        case 1:
            MoveCurrent(y,x,1,kr);
            break;
        case 2:
            MoveCurrent(y,x,2,kr);
            break;
        case 3:
            MoveCurrent(y,x,3,kr);
            break;
        case 4:
            MoveCurrent(y,x,4,kr);
            break;
        case 5:
            MoveCurrent(y,x,5,kr);
            break;
        case 6:
            MoveCurrent(y,x,6,kr);
            break;
        case 7:
            MoveCurrent(y,x,7,kr);
            break;
        case 8:
            MoveCurrent(y,x,8,kr);
            break;
        case 9:
            MoveCurrent(y,x,9,kr);
            break;
        }
    }
    IsEmpty[y-1][x-1] = false;
    if(y<=3&&x<=3)
        Map[y-1][x-1] = kr;
    else if(y<=6&&x<=3)
        Map[y][x-1] = kr;
    else if(y<=9&&x<=3)
        Map[y+1][x-1] = kr;
    else if(x<=6&&y<=3)
        Map[y-1][x] = kr;
    else if(x<=9&&y<=3)
        Map[y-1][x+1] = kr;
    else if(x<=6&&y<=6)
        Map[y][x] = kr;
    else if(x<=6&&y<=9)
        Map[y+1][x] = kr;
    else if(x<=9&&y<=6)
        Map[y][x+1] = kr;
    else
        Map[y+1][x+1] = kr;
    if(kr==Player2)
        UpdateMap(Player2);
    else if(kr==Player1)
        UpdateMap(Player1);
    ChangePlace(y,x);
}
void Mapa::ChangePlace(int y,int x) //Nastepne polozenie
{
    int t1=y,t2=x;;
    if(y<=3&&x<=3)
    {
        y--;
        x--;
    }
    else if(y<=6&&x<=3)
        x--;
    else if(y<=9&&x<=3)
    {
        y++;
        x--;
    }
    else if(x<=6&&y<=3)
        y--;
    else if(x<=6&&y<=6)
    {
        x=x;
        y=y;
    }
    else if(x<=9&&y<=3)
    {
        y--;
        x++;
    }
    else if(x<=9&&y<=6)
    {
        x++;
    }
    else if(x<=6&&x<=9)
        y++;
    else if(x<=9&&y<=9)
    {
        x++;
        y++;
    }
    if((y==0||y==4||y==8)&&(x==0||x==4||x==8))
        CurrentPlace = 1;
    else if((y==1||y==5||y==9)&&(x==0||x==4||x==8))
        CurrentPlace = 2;
    else if((y==2||y==6||y==10)&&(x==0||x==4||x==8))
        CurrentPlace = 3;
    else if((y==0||y==4||y==8)&&(x==1||x==5||x==9))
        CurrentPlace = 4;
    else if((y==1||y==5||y==9)&&(x==1||x==5||x==9))
        CurrentPlace = 5;
    else if((y==2||y==6||y==10)&&(x==1||x==5||x==9))
        CurrentPlace = 6;
    else if((y==0||y==4||y==8)&&(x==2||x==6||x==10))
        CurrentPlace = 7;
    else if((y==1||y==5||y==9)&&(x==2||x==6||x==10))
        CurrentPlace = 8;
    else if((y==2||y==6||y==10)&&(x==2||x==6||x==10))
        CurrentPlace = 9;

    if(OO[NextPrzedzial(t1,t2)]==true||XX[NextPrzedzial(t1,t2)]==true||EmptyPrzedzial(t1,t2)==false)
        CurrentPlace = 0;
}
bool Mapa::EmptyPrzedzial(int y,int x) //Sprawdcza czy obecny przedzial jest pusty
{
    int i,j;
    switch(NextPrzedzial(y,x))
    {
    case 0:
        for(i = 0; i<3; i++)
            for(j = 0; j<3; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 1:
        for(i = 4; i<=6; i++)
            for(j = 0; j<3; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 2:
        for(i = 8; i<=10; i++)
            for(j = 0; j<3; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 3:
        for(i = 0; i<3; i++)
            for(j = 4; j<=6; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 4:
        for(i = 4; i<=6; i++)
            for(j = 4; j<=6; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 5:
        for(i = 8; i<=10; i++)
            for(j = 4; j<=6; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 6:
        for(i = 0; i<3; i++)
            for(j = 8; j<=10; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 7:
        for(i = 4; i<=6; i++)
            for(j = 8; j<=10; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    case 8:
        for(i = 8; i<=10; i++)
            for(j = 8; j<=10; j++)
                if(Map[i][j]=='*')
                    return true;
        break;
    }
    return false;
}
bool Mapa::CheckSmallWin(const char k) //Sprawdza wygrana malej planszy
{
    if(Map[0][0]==Map[0][1]&&Map[0][1]==Map[0][2]&&Map[0][0]==k)
        return true;
    if(Map[0][0]==Map[1][0]&&Map[1][0]==Map[2][0]&&Map[0][0]==k)
        return true;
    if(Map[0][0]==Map[1][1]&&Map[1][1]==Map[2][2]&&Map[0][0]==k)
        return true;
    if(Map[0][2]==Map[1][1]&&Map[1][1]==Map[2][0]&&Map[0][2]==k)
        return true;
    if(Map[0][1]==Map[1][1]&&Map[1][1]==Map[2][1]&&Map[0][1]==k)
        return true;
    if(Map[0][2]==Map[1][2]&&Map[1][2]==Map[2][2]&&Map[0][2]==k)
        return true;
    if(Map[1][0]==Map[1][1]&&Map[1][1]==Map[1][2]&&Map[1][0]==k)
        return true;
    if(Map[2][0]==Map[2][1]&&Map[2][1]==Map[2][2]&&Map[2][0]==k)
        return true;
    if(Map[4][0]==Map[5][0]&&Map[5][0]==Map[6][0]&&Map[4][0]==k)
        return true;
    if(Map[4][1]==Map[5][1]&&Map[5][1]==Map[6][1]&&Map[4][1]==k)
        return true;
    if(Map[4][2]==Map[5][2]&&Map[5][2]==Map[6][2]&&Map[4][2]==k)
        return true;
    if(Map[4][0]==Map[4][1]&&Map[4][1]==Map[4][2]&&Map[4][2]==k)
        return true;
    if(Map[5][0]==Map[5][1]&&Map[5][1]==Map[5][2]&&Map[5][2]==k)
        return true;
    if(Map[6][0]==Map[6][1]&&Map[6][1]==Map[6][2]&&Map[6][2]==k)
        return true;
    if(Map[4][0]==Map[5][1]&&Map[5][1]==Map[6][2]&&Map[6][2]==k)
        return true;
    if(Map[4][2]==Map[5][1]&&Map[5][1]==Map[6][0]&&Map[6][0]==k)
        return true;
    if(Map[8][0]==Map[9][0]&&Map[9][0]==Map[10][0]&&Map[8][0]==k)
        return true;
    if(Map[8][1]==Map[9][1]&&Map[9][1]==Map[10][1]&&Map[10][1]==k)
        return true;
    if(Map[8][2]==Map[9][2]&&Map[9][2]==Map[10][2]&&Map[10][2]==k)
        return true;
    if(Map[8][0]==Map[8][1]&&Map[8][1]==Map[8][2]&&Map[8][2]==k)
        return true;
    if(Map[9][0]==Map[9][1]&&Map[9][1]==Map[9][2]&&Map[9][2]==k)
        return true;
    if(Map[10][0]==Map[10][1]&&Map[10][1]==Map[10][2]&&Map[10][2]==k)
        return true;
    if(Map[8][0]==Map[9][1]&&Map[9][1]==Map[10][2]&&Map[10][2]==k)
        return true;
    if(Map[8][2]==Map[9][1]&&Map[9][1]==Map[10][0]&&Map[8][2]==k)
        return true;
    if(Map[0][4]==Map[1][4]&&Map[1][4]==Map[2][4]&&Map[0][4]==k)
        return true;
    if(Map[0][5]==Map[1][5]&&Map[1][5]==Map[2][5]&&Map[2][5]==k)
        return true;
    if(Map[0][6]==Map[1][6]&&Map[1][6]==Map[2][6]&&Map[2][6]==k)
        return true;
    if(Map[0][4]==Map[0][5]&&Map[0][5]==Map[0][6]&&Map[0][5]==k)
        return true;
    if(Map[1][4]==Map[1][5]&&Map[1][5]==Map[1][6]&&Map[1][6]==k)
        return true;
    if(Map[2][4]==Map[2][5]&&Map[2][5]==Map[2][6]&&Map[2][5]==k)
        return true;
    if(Map[0][4]==Map[1][5]&&Map[1][5]==Map[2][6]&&Map[2][6]==k)
        return true;
    if(Map[0][6]==Map[1][5]&&Map[1][5]==Map[2][4]&&Map[2][4]==k)
        return true;
    if(Map[4][4]==Map[5][4]&&Map[5][4]==Map[6][4]&&Map[6][4]==k)
        return true;
    if(Map[4][5]==Map[5][5]&&Map[5][5]==Map[6][5]&&Map[6][5]==k)
        return true;
    if(Map[4][6]==Map[5][6]&&Map[5][6]==Map[6][6]&&Map[6][6]==k)
        return true;
    if(Map[4][4]==Map[4][5]&&Map[4][5]==Map[4][6]&&Map[4][6]==k)
        return true;
    if(Map[5][4]==Map[5][5]&&Map[5][5]==Map[5][6]&&Map[5][5]==k)
        return true;
    if(Map[6][4]==Map[6][5]&&Map[6][5]==Map[6][6]&&Map[6][4]==k)
        return true;
    if(Map[4][4]==Map[5][5]&&Map[5][5]==Map[6][6]&&Map[6][6]==k)
        return true;
    if(Map[4][6]==Map[5][5]&&Map[5][5]==Map[6][4]&&Map[6][4]==k)
        return true;
    if(Map[8][4]==Map[9][4]&&Map[9][4]==Map[10][4]&&Map[9][4]==k)
        return true;
    if(Map[8][5]==Map[9][5]&&Map[9][5]==Map[10][5]&&Map[10][5]==k)
        return true;
    if(Map[8][6]==Map[9][6]&&Map[9][6]==Map[10][6]&&Map[10][6]==k)
        return true;
    if(Map[8][4]==Map[8][5]&&Map[8][5]==Map[8][6]&&Map[8][5]==k)
        return true;
    if(Map[9][4]==Map[9][5]&&Map[9][5]==Map[9][6]&&Map[9][4]==k)
        return true;
    if(Map[10][4]==Map[10][5]&&Map[10][5]==Map[10][6]&&Map[10][4]==k)
        return true;
    if(Map[8][4]==Map[9][5]&&Map[9][5]==Map[10][6]&&Map[8][4]==k)
        return true;
    if(Map[8][6]==Map[9][5]&&Map[9][5]==Map[10][4]&&Map[9][5]==k)
        return true;
    if(Map[0][8]==Map[1][8]&&Map[1][8]==Map[2][8]&&Map[2][8]==k)
        return true;
    if(Map[0][9]==Map[1][9]&&Map[1][9]==Map[2][9]&&Map[0][9]==k)
        return true;
    if(Map[0][10]==Map[1][10]&&Map[1][10]==Map[2][10]&&Map[0][10]==k)
        return true;
    if(Map[0][8]==Map[0][9]&&Map[0][9]==Map[0][10]&&Map[0][8]==k)
        return true;
    if(Map[1][8]==Map[1][9]&&Map[1][9]==Map[1][10]&&Map[1][9]==k)
        return true;
    if(Map[2][8]==Map[2][9]&&Map[2][9]==Map[2][10]&&Map[2][10]==k)
        return true;
    if(Map[0][8]==Map[1][9]&&Map[1][9]==Map[2][10]&&Map[2][10]==k)
        return true;
    if(Map[0][10]==Map[1][9]&&Map[1][9]==Map[2][8]&&Map[0][10]==k)
        return true;
    if(Map[4][8]==Map[5][8]&&Map[5][8]==Map[6][8]&&Map[6][8]==k)
        return true;
    if(Map[4][9]==Map[5][9]&&Map[5][9]==Map[6][9]&&Map[6][9]==k)
        return true;
    if(Map[4][10]==Map[5][10]&&Map[5][10]==Map[6][10]&&Map[6][10]==k)
        return true;
    if(Map[4][8]==Map[4][9]&&Map[4][9]==Map[4][10]&&Map[4][8]==k)
        return true;
    if(Map[5][8]==Map[5][9]&&Map[5][9]==Map[5][10]&&Map[5][8]==k)
        return true;
    if(Map[6][8]==Map[6][9]&&Map[6][9]==Map[6][10]&&Map[6][8]==k)
        return true;
    if(Map[4][8]==Map[5][9]&&Map[5][9]==Map[6][10]&&Map[5][9]==k)
        return true;
    if(Map[4][10]==Map[5][9]&&Map[5][9]==Map[6][8]&&Map[6][8]==k)
        return true;
    if(Map[8][8]==Map[9][8]&&Map[9][8]==Map[10][8]&&Map[8][8]==k)
        return true;
    if(Map[8][9]==Map[9][9]&&Map[9][9]==Map[10][9]&&Map[8][9]==k)
        return true;
    if(Map[8][10]==Map[9][10]&&Map[9][10]==Map[10][10]&&Map[8][10]==k)
        return true;
    if(Map[8][8]==Map[8][9]&&Map[8][9]==Map[8][10]&&Map[8][8]==k)
        return true;
    if(Map[9][8]==Map[9][9]&&Map[9][9]==Map[9][10]&&Map[9][8]==k)
        return true;
    if(Map[10][8]==Map[10][9]&&Map[10][9]==Map[10][10]&&Map[10][10]==k)
        return true;
    if(Map[8][8]==Map[9][9]&&Map[9][9]==Map[10][10]&&Map[8][8]==k)
        return true;
    if(Map[8][10]==Map[9][9]&&Map[9][9]==Map[10][8]&&Map[8][10]==k)
        return true;
    return false;
}
int Mapa::Wprowadz() //Wprowadz wspolrzedne dla calej mapy
{
    char g;
    do
    {
        g = getch();
        g-=48;
    }
    while(g>9||g<1);
    return g;
}
Mapa::~Mapa()
{
    int i;
    for(i = 0; i<MAP_SIZE; i++)
        delete Map[i];
    delete[] Map;
    for(i = 0; i<MAP_SIZE; i++)
        delete IsEmpty[i];
    delete[] IsEmpty;
    delete[] OO;
    delete[] XX;
}
bool Mapa::CheckWin() //Sprawdza wygrana
{
    if((OO[0]==OO[1]&&OO[1]==OO[2]&&OO[2]==true)||(XX[0]==XX[1]&&XX[1]==XX[2]&&XX[2]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[3]==OO[4]&&OO[4]==OO[5]&&OO[5]==true)||(XX[3]==XX[4]&&XX[4]==XX[5]&&XX[5]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[6]==OO[7]&&OO[7]==OO[8]&&OO[8]==true)||(XX[6]==XX[7]&&XX[7]==XX[8]&&XX[8]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[0]==OO[3]&&OO[3]==OO[6]&&OO[6]==true)||(XX[0]==XX[3]&&XX[3]==XX[6]&&XX[6]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[1]==OO[4]&&OO[4]==OO[7]&&OO[7]==true)||(XX[1]==XX[4]&&XX[4]==XX[7]&&XX[7]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[2]==OO[5]&&OO[5]==OO[8]&&OO[8]==true)||(XX[2]==XX[5]&&XX[5]==XX[8]&&XX[8]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[0]==OO[4]&&OO[4]==OO[8]&&OO[8]==true)||(XX[0]==XX[4]&&XX[4]==XX[8]&&XX[8]==true))
    {
        WIN=true;
        return true;
    }
    else if((OO[6]==OO[4]&&OO[4]==OO[2]&&OO[2]==true)||(XX[6]==XX[4]&&XX[4]==XX[2]&&XX[2]==true))
    {
        WIN=true;
        return true;
    }
    return false;
}
int Mapa::Przedzial(int y,int x) //Sprawdza w ktorym przedziale postawilismy kolko badz krzyzyk
{
    if(y<=3&&x<=3)
        return 0;
    else if(y<=3&&x<=6)
        return 1;
    else if(y<=3&&x<=10)
        return 2;
    else if(y<=6&&x<=3)
        return 3;
    else if(y<=6&&x<=6)
        return 4;
    else if(y<=6&&x<=10)
        return 5;
    else if(y<=9&&x<=3)
        return 6;
    else if(y<=9&&x<=6)
        return 7;
    else return 8;
    return 0;
}
void Mapa::Zamien() //Zamienia male wygrane pole w same X/O
{
    int i;
    for( i = 0; i<9; i++)
        if(XX[i])
            switch(i)
            {
            case 0:
                Map[0][0] = Map[0][1] = Map[0][2] = Map[1][0] = Map[1][1] = Map[1][2]=Player1;
                Map[2][0] = Map[2][1] = Map[2][2] = Player1;
                break;
            case 1:
                Map[4][0] = Map[4][1] = Map[4][2] = Map[5][0] = Map[5][1] = Map[5][2]=Player1;
                Map[6][0] = Map[6][1] = Map[6][2] = Player1;
                break;
            case 2:
                Map[8][0] = Map[8][1] = Map[8][2] = Map[9][0] = Map[9][1] = Map[9][2]=Player1;
                Map[10][0] = Map[10][1] = Map[10][2] = Player1;
                break;
            case 3:
                Map[0][4] = Map[0][5] = Map[0][6] = Map[1][4] = Map[1][5] = Map[1][6]=Player1;
                Map[2][4] = Map[2][5] = Map[2][6] = Player1;
                break;
            case 4:
                Map[4][4] = Map[4][5] = Map[4][6] = Map[5][4] = Map[5][5] = Map[5][6]=Player1;
                Map[6][4] = Map[6][5] = Map[6][6] = Player1;
                break;
            case 5:
                Map[8][4] = Map[8][5] = Map[8][6] = Map[9][4] = Map[9][5] = Map[9][6]=Player1;
                Map[10][4] = Map[10][5] = Map[10][6] = Player1;
                break;
            case 6:
                Map[0][8] = Map[0][9] = Map[0][10] = Map[1][8] = Map[1][9] = Map[1][10]=Player1;
                Map[2][8] = Map[2][9] = Map[2][10] = Player1;
                break;
            case 7:
                Map[4][8] = Map[4][9] = Map[4][10] = Map[5][8] = Map[5][9] = Map[5][10]=Player1;
                Map[6][8] = Map[6][9] = Map[6][10] = Player1;
                break;
            case 8:
                Map[8][8] = Map[8][9] = Map[8][10] = Map[9][8] = Map[9][9] = Map[9][10]=Player1;
                Map[10][8] = Map[10][9] = Map[10][10] = Player1;
                break;
            }
        else if(OO[i])
            switch(i)
            {
            case 0:
                Map[0][0] = Map[0][1] = Map[0][2] = Map[1][0] = Map[1][1] = Map[1][2]=Player2;
                Map[2][0] = Map[2][1] = Map[2][2] = Player2;
                break;
            case 1:
                Map[4][0] = Map[4][1] = Map[4][2] = Map[5][0] = Map[5][1] = Map[5][2]=Player2;
                Map[6][0] = Map[6][1] = Map[6][2] = Player2;
                break;
            case 2:
                Map[8][0] = Map[8][1] = Map[8][2] = Map[9][0] = Map[9][1] = Map[9][2]=Player2;
                Map[10][0] = Map[10][1] = Map[10][2] = Player2;
                break;
            case 3:
                Map[0][4] = Map[0][5] = Map[0][6] = Map[1][4] = Map[1][5] = Map[1][6]=Player2;
                Map[2][4] = Map[2][5] = Map[2][6] = Player2;
                break;
            case 4:
                Map[4][4] = Map[4][5] = Map[4][6] = Map[5][4] = Map[5][5] = Map[5][6]=Player2;
                Map[6][4] = Map[6][5] = Map[6][6] = Player2;
                break;
            case 5:
                Map[8][4] = Map[8][5] = Map[8][6] = Map[9][4] = Map[9][5] = Map[9][6]=Player2;
                Map[10][4] = Map[10][5] = Map[10][6] = Player2;
                break;
            case 6:
                Map[0][8] = Map[0][9] = Map[0][10] = Map[1][8] = Map[1][9] = Map[1][10]=Player2;
                Map[2][8] = Map[2][9] = Map[2][10] = Player2;
                break;
            case 7:
                Map[4][8] = Map[4][9] = Map[4][10] = Map[5][8] = Map[5][9] = Map[5][10]=Player2;
                Map[6][8] = Map[6][9] = Map[6][10] = Player2;
                break;
            case 8:
                Map[8][8] = Map[8][9] = Map[8][10] = Map[9][8] = Map[9][9] = Map[9][10]=Player2;
                Map[10][8] = Map[10][9] = Map[10][10] = Player2;
                break;
            }
}
void Mapa::MoveCurrent(int& y,int& x,int pos,char g) //Wprowadz wspolrzedne dla obecnej pozycji
{
    HANDLE hOut;
    int wyznacznik;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    char q;
    switch(pos)
    {
    case 1:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q>3||q<1);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q>3||q<1);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 2:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q>3||q<1);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q>6||q<4);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 3:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q>3||q<1);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q>9||q<=6);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 4:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<4||q>6);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q>3||q<1);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 5:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<4||q>6);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q<4||q>6);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 6:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<4||q>6);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q<=6||q>9);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 7:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<=6||q>9);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q<1||q>3);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 8:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<=6||q>9);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q<4||q>6);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    case 9:
        do
        {
            do
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
                cout<<"Podaj wsp\242\210rz\251dne: ";
                do
                {
                    q=getch();
                    q-=48;
                }
                while(q<=6||q>9);
                x=q;
                cout<<x;
                SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                cout<<"\nPodaj wsp\242\210rz\251dne: ";
                do
                {
                    q = getch();
                    q-=48;
                    if(q==-40)break;
                }
                while(q<=6||q>9);
                if(q==-40)
                {
                    system("cls");
                    cout<<*this;
                    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<"Gracz: ";
                    if(g==Player1)
                        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else
                        SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    cout<<g<<endl;
                }
            }
            while(q==-40);
            y=q;
            cout<<y;
            SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
            wyznacznik = Przedzial(x,y);
            ChangePlace(y,x);
            if(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true))
                cout<<"\nPole niedost\251pne\n";
        }
        while(IsEmpty[y-1][x-1]==false||(OO[wyznacznik]==true||XX[wyznacznik]==true));
        break;
    }
}
int Mapa::NextPrzedzial(int y,int x) //Sprawdza gdzie bedzie nastepny ruch
{
    if((y==1||y==4||y==7)&&(x==1||x==4||x==7) )
        return 0;
    else if((y==2||y==5||y==8)&&(x==1||x==4||x==7))
        return 1;
    else if((y==3||y==6||y==9)&&(x==1||x==4||x==7))
        return 2;
    else if((y==1||y==4||y==7)&&(x==2||x==5||x==8))
        return 3;
    else if((y==2||y==5||y==8)&&(x==2||x==5||x==8))
        return 4;
    else if((y==3||y==6||y==9)&&(x==2||x==5||x==8))
        return 5;
    else if((y==1||y==4||y==7)&&(x==3||x==6||x==9))
        return 6;
    else if((y==2||y==5||y==8)&&(x==3||x==6||x==9))
        return 7;
    else if((y==3||y==6||y==9)&&(x==3||x==6||x==9))
        return 8;
    return 9;
}
void Mapa::UpdateMap(const char k) //Ustawia aby obecny przedzial zamienil sie w same X\O
{
    if(XX[0]==false&&OO[0]==false)
    {
        if(Map[0][0]==Map[0][1]&&Map[0][1]==Map[0][2]&&Map[0][0]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[0][0]==Map[1][0]&&Map[1][0]==Map[2][0]&&Map[0][0]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[0][0]==Map[1][1]&&Map[1][1]==Map[2][2]&&Map[0][0]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[0][2]==Map[1][1]&&Map[1][1]==Map[2][0]&&Map[0][2]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[0][1]==Map[1][1]&&Map[1][1]==Map[2][1]&&Map[0][1]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[0][2]==Map[1][2]&&Map[1][2]==Map[2][2]&&Map[0][2]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[1][0]==Map[1][1]&&Map[1][1]==Map[1][2]&&Map[1][0]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
        else if(Map[2][0]==Map[2][1]&&Map[2][1]==Map[2][2]&&Map[2][0]==k)
        {
            if(k==Player1)
                XX[0] = true;
            else
                OO[0] = true;
        }
    }
    if(XX[1]==false&&OO[1]==false)
    {
        if(Map[4][0]==Map[5][0]&&Map[5][0]==Map[6][0]&&Map[4][0]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[4][1]==Map[5][1]&&Map[5][1]==Map[6][1]&&Map[4][1]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[4][2]==Map[5][2]&&Map[5][2]==Map[6][2]&&Map[4][2]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[4][0]==Map[4][1]&&Map[4][1]==Map[4][2]&&Map[4][2]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[5][0]==Map[5][1]&&Map[5][1]==Map[5][2]&&Map[5][2]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[6][0]==Map[6][1]&&Map[6][1]==Map[6][2]&&Map[6][2]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[4][0]==Map[5][1]&&Map[5][1]==Map[6][2]&&Map[6][2]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
        else if(Map[4][2]==Map[5][1]&&Map[5][1]==Map[6][0]&&Map[6][0]==k)
        {
            if(k==Player1)
                XX[1] = true;
            else
                OO[1] = true;
        }
    }
    if(XX[2]==false&&OO[2]==false)
    {
        if(Map[8][0]==Map[9][0]&&Map[9][0]==Map[10][0]&&Map[8][0]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[8][1]==Map[9][1]&&Map[9][1]==Map[10][1]&&Map[10][1]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[8][2]==Map[9][2]&&Map[9][2]==Map[10][2]&&Map[10][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[8][0]==Map[8][1]&&Map[8][1]==Map[8][2]&&Map[8][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[9][0]==Map[9][1]&&Map[9][1]==Map[9][2]&&Map[9][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[10][0]==Map[10][1]&&Map[10][1]==Map[10][2]&&Map[10][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[8][0]==Map[9][1]&&Map[9][1]==Map[10][2]&&Map[10][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
        else if(Map[8][2]==Map[9][1]&&Map[9][1]==Map[10][0]&&Map[8][2]==k)
        {
            if(k==Player1)
                XX[2] = true;
            else
                OO[2] = true;
        }
    }
    if(XX[3]==false&&OO[3]==false)
    {
        if(Map[0][4]==Map[1][4]&&Map[1][4]==Map[2][4]&&Map[0][4]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[0][5]==Map[1][5]&&Map[1][5]==Map[2][5]&&Map[2][5]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[0][6]==Map[1][6]&&Map[1][6]==Map[2][6]&&Map[2][6]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[0][4]==Map[0][5]&&Map[0][5]==Map[0][6]&&Map[0][5]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[1][4]==Map[1][5]&&Map[1][5]==Map[1][6]&&Map[1][6]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[2][4]==Map[2][5]&&Map[2][5]==Map[2][6]&&Map[2][5]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[0][4]==Map[1][5]&&Map[1][5]==Map[2][6]&&Map[2][6]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
        else if(Map[0][6]==Map[1][5]&&Map[1][5]==Map[2][4]&&Map[2][4]==k)
        {
            if(k==Player1)
                XX[3] = true;
            else
                OO[3] = true;
        }
    }
    if(XX[4]==false&&OO[4]==false)
    {
        if(Map[4][4]==Map[5][4]&&Map[5][4]==Map[6][4]&&Map[6][4]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[4][5]==Map[5][5]&&Map[5][5]==Map[6][5]&&Map[6][5]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[4][6]==Map[5][6]&&Map[5][6]==Map[6][6]&&Map[6][6]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[4][4]==Map[4][5]&&Map[4][5]==Map[4][6]&&Map[4][6]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[5][4]==Map[5][5]&&Map[5][5]==Map[5][6]&&Map[5][5]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[6][4]==Map[6][5]&&Map[6][5]==Map[6][6]&&Map[6][4]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[4][4]==Map[5][5]&&Map[5][5]==Map[6][6]&&Map[6][6]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
        else if(Map[4][6]==Map[5][5]&&Map[5][5]==Map[6][4]&&Map[6][4]==k)
        {
            if(k==Player1)
                XX[4] = true;
            else
                OO[4] = true;
        }
    }
    if(XX[5]==false&&OO[5]==false)
    {
        if(Map[8][4]==Map[9][4]&&Map[9][4]==Map[10][4]&&Map[9][4]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[8][5]==Map[9][5]&&Map[9][5]==Map[10][5]&&Map[10][5]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[8][6]==Map[9][6]&&Map[9][6]==Map[10][6]&&Map[10][6]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[8][4]==Map[8][5]&&Map[8][5]==Map[8][6]&&Map[8][5]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[9][4]==Map[9][5]&&Map[9][5]==Map[9][6]&&Map[9][4]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[10][4]==Map[10][5]&&Map[10][5]==Map[10][6]&&Map[10][4]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[8][4]==Map[9][5]&&Map[9][5]==Map[10][6]&&Map[8][4]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
        else if(Map[8][6]==Map[9][5]&&Map[9][5]==Map[10][4]&&Map[9][5]==k)
        {
            if(k==Player1)
                XX[5] = true;
            else
                OO[5] = true;
        }
    }
    if(XX[6]==false&&OO[6]==false)
    {
        if(Map[0][8]==Map[1][8]&&Map[1][8]==Map[2][8]&&Map[2][8]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[0][9]==Map[1][9]&&Map[1][9]==Map[2][9]&&Map[0][9]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[0][10]==Map[1][10]&&Map[1][10]==Map[2][10]&&Map[0][10]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[0][8]==Map[0][9]&&Map[0][9]==Map[0][10]&&Map[0][8]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[1][8]==Map[1][9]&&Map[1][9]==Map[1][10]&&Map[1][9]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[2][8]==Map[2][9]&&Map[2][9]==Map[2][10]&&Map[2][10]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[0][8]==Map[1][9]&&Map[1][9]==Map[2][10]&&Map[2][10]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
        else if(Map[0][10]==Map[1][9]&&Map[1][9]==Map[2][8]&&Map[0][10]==k)
        {
            if(k==Player1)
                XX[6] = true;
            else
                OO[6] = true;
        }
    }
    if(XX[7]==false&&OO[7]==false)
    {
        if(Map[4][8]==Map[5][8]&&Map[5][8]==Map[6][8]&&Map[6][8]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[4][9]==Map[5][9]&&Map[5][9]==Map[6][9]&&Map[6][9]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[4][10]==Map[5][10]&&Map[5][10]==Map[6][10]&&Map[6][10]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[4][8]==Map[4][9]&&Map[4][9]==Map[4][10]&&Map[4][8]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[5][8]==Map[5][9]&&Map[5][9]==Map[5][10]&&Map[5][8]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[6][8]==Map[6][9]&&Map[6][9]==Map[6][10]&&Map[6][8]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[4][8]==Map[5][9]&&Map[5][9]==Map[6][10]&&Map[5][9]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
        else if(Map[4][10]==Map[5][9]&&Map[5][9]==Map[6][8]&&Map[6][8]==k)
        {
            if(k==Player1)
                XX[7] = true;
            else
                OO[7] = true;
        }
    }
    if(XX[8]==false&&OO[8]==false)
    {
        if(Map[8][8]==Map[9][8]&&Map[9][8]==Map[10][8]&&Map[8][8]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[8][9]==Map[9][9]&&Map[9][9]==Map[10][9]&&Map[8][9]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[8][10]==Map[9][10]&&Map[9][10]==Map[10][10]&&Map[8][10]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[8][8]==Map[8][9]&&Map[8][9]==Map[8][10]&&Map[8][8]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[9][8]==Map[9][9]&&Map[9][9]==Map[9][10]&&Map[9][8]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[10][8]==Map[10][9]&&Map[10][9]==Map[10][10]&&Map[10][10]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[8][8]==Map[9][9]&&Map[9][9]==Map[10][10]&&Map[8][8]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
        else if(Map[8][10]==Map[9][9]&&Map[9][9]==Map[10][8]&&Map[8][10]==k)
        {
            if(k==Player1)
                XX[8] = true;
            else
                OO[8] = true;
        }
    }
}
ostream& operator<<(ostream& os,Mapa& m) //Wszystko wyswietla
{
    m.Zamien();
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    if(m.CurrentPlace==1||m.CurrentPlace==2||m.CurrentPlace==3)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    else if (m.CurrentPlace==0)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    os<<"        123";
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    if(m.CurrentPlace==4||m.CurrentPlace==5||m.CurrentPlace==6)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    else if (m.CurrentPlace==0)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    os<<"\t456";
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    os<<"\t";
    if(m.CurrentPlace==7||m.CurrentPlace==8||m.CurrentPlace==9)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    else if (m.CurrentPlace==0)
        SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
    os<<"789\n";
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    if(m.CurrentPlace==1||m.CurrentPlace==7||m.CurrentPlace==4)
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    else if(m.CurrentPlace==0)
        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    os<<"      1 ";
    for(int i = 0; i<MAP_SIZE; i++)
    {
        for(int c = 0; c<MAP_SIZE2; c++)
        {
            if(m.Map[i][c]==Player1)
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            else if(m.Map[i][c]==Player2)
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            else
                SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
            if(m.Map[i][c]!='\n')
                os<<m.Map[i][c];
            else if(i!=2&&i!=6)
            {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                if(i==4||i==5||i==3)
                {
                    if(m.CurrentPlace==2||m.CurrentPlace==8||m.CurrentPlace==5)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else if(m.CurrentPlace==0)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    os<<"\n      "<<i+1<<" ";
                }
                else if(i>=6&&i<=9)
                {
                    if(m.CurrentPlace==3||m.CurrentPlace==6||m.CurrentPlace==9)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else if(m.CurrentPlace==0)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    os<<"\n      "<<i<<" ";
                }
                else if(i==10);//Nothing To Do
                else
                {
                    if(m.CurrentPlace==1||m.CurrentPlace==7||m.CurrentPlace==4)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    else if(m.CurrentPlace==0)
                        SetConsoleTextAttribute(hOut,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                    os<<"\n      "<<i+2<<" ";
                }
            }
            else
                os<<endl;
        }
    }
    SetConsoleTextAttribute(hOut,FOREGROUND_GREEN);
    cout<<endl;
    return os;
}
