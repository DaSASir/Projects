#include <iostream>
#include "TickyTack.h"

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    TickTackToe game;
    game.playPC();

    return 0;
}
