#include <windows.h>
#include <.\classes\colorir.h"


void colorirTexto(int cor){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, cor);
}
