//Luan Emanuel R. Argentato RA: 2184611
//Gustavo duzzi             RA: 2214047
//Guilherme Santos Gollino  RA: 2226090

#include <windows.h>
#include ".\classes\colorir.h"


void colorirTexto(int cor){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, cor);
}

void setConsoleColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
