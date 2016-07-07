#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;

class Mapa
{
private:
    int CurrentPlace;
    char** Map;
    bool** IsEmpty;
    bool WIN;
    bool* XX;
    bool* OO;
    int NextPrzedzial(int,int);
    int Przedzial(int,int);
    int Wprowadz();
    bool CheckSmallWin(const char);
    bool EmptyPrzedzial(int,int);
    bool CheckWin();
    void MoveCurrent(int&,int&,int,const char);
    void UpdateMap(const char);
    void ChangePlace(int,int);
    void Ruch(const char);
    void Zamien();
    void Bot();
    void RuchBot(const char);
    void Reset();
    bool Remis();
    friend ostream& operator<<(ostream&,Mapa&);
public:
    Mapa();
    ~Mapa();
    void Start();
};



#endif // MAPA_H_INCLUDED
