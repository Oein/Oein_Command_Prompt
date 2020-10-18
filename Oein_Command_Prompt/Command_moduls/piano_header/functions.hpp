#pragma once

#include "include.hpp"

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printNemo(int i , bool del) {
    if (i == 0) gotoxy(3, 10);
    else if (i == 1) gotoxy(6, 10);
    else if (i == 2) gotoxy(9, 10);
    else if (i == 3) gotoxy(12, 10);
    else if (i == 4) gotoxy(15, 10);
    else if (i == 5) gotoxy(20, 10);
    else if (i == 6) gotoxy(24, 10);
    else if (i == 7) gotoxy(27, 10);
    else if (i == 8) gotoxy(30, 10);
    else if (i == 9) gotoxy(33, 10);
    else if (i == 10) gotoxy(36, 10);
    else if (i == 11) gotoxy(39, 10);
    else if (i == 12) gotoxy(44, 10); //q
    else if (i == 13) gotoxy(48, 10); //2
    else if (i == 14) gotoxy(51, 10); //w
    else if (i == 15) gotoxy(54, 10); //3
    else if (i == 16) gotoxy(57, 10); //e
    else if (i == 17) gotoxy(63, 10); //r
    else if (i == 18) gotoxy(66, 10); //5
    else if (i == 19) gotoxy(69, 10); //t
    else if (i == 20) gotoxy(72, 10); //6
    else if (i == 21) gotoxy(75, 10); //y
    else if (i == 22) gotoxy(78, 10); //7
    else if (i == 23) gotoxy(82, 10); //u
    else if (i == 24) gotoxy(87, 10); //i

    if (del) printf("  ");
    else printf("бс");
}