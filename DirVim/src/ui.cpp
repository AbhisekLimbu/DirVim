#include "ui.h"
#include <ncurses.h>

int runUI() {
    initscr();          // Start ncurses mode
    printw("Welcome to Vexplore!"); // Print a message
    refresh();          // Refresh screen
    getch();            // Wait for user input
    endwin();           // End ncurses mode

    return 0;
}
