#include "Mapa.h"
#include <windows.h>
#include <new>
using namespace std;
int main()
{
    char* buff = new char[sizeof(Mapa)];
    Mapa* Game = new (buff) Mapa;
    Game->Start();
    Game->~Mapa();
    delete[] buff;
}
