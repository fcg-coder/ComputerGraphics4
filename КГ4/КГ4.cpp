 //  https://github.com/ahuynh359/Graphics
//https://developerinsider.co/graphics-graphics-h-c-programming/
//http://mycpp.ru/cpp/scpp/cppd_graphics.h.htm
#include <iostream>
#include <windows.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <locale.h>
#include "graphics.h"
#include "libOfFunctions.cpp"
#pragma comment(lib,"graphics.lib")

using namespace std;

int main()
{
    srand(time(NULL));
    initwindow(SIZE_OF_WINDOW, SIZE_OF_WINDOW); //"Инициализация" окна размером Х на У 
    boolean WORK = true;
    char trasport, BUTTON;
    cleardevice();
    random();
    MENU();
    while (1) {
        WORK = true;
   

        while ((BUTTON = getch()) && (WORK == true)) {
            switch (BUTTON)
            {
            case '/':
                cleardevice();
                random();
                MENU();
            default:
                MENU();
                trasport = BUTTON;
                MoveLine(trasport);
                break;
            }
        }
    }
    closegraph();
    return 0;
}
