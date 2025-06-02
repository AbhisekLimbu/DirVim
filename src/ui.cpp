#include "ui.h"
#include "explorer.h"

#include <ncurses.h>
#include <vector>
#include <string>

int runUI() {
    initscr();              // Start ncurses
    noecho();               // Don’t display typed characters
    cbreak();               // Disable line buffering
    keypad(stdscr, TRUE);   // Enable arrow keys and function keys

    std::string currentPath = ".";
    std::vector<std::string> items = listDirectory(currentPath);

    int pos = 0;  // Currently selected item
    int ch;

    while (true) {
        clear();
        mvprintw(0, 0, "Vexplore - %s", currentPath.c_str());
        mvprintw(1, 0, "Press j/k to navigate, q to quit");

        for (int i = 0; i < items.size(); ++i) {
            if (i == pos) {
                attron(A_REVERSE); // Highlight selected item
                mvprintw(i + 3, 2, "%s", items[i].c_str());
                attroff(A_REVERSE);
            } else {
                mvprintw(i + 3, 2, "%s", items[i].c_str());
            }
        }

        ch = getch();

        if (ch == 'q') break;
        else if ((ch == 'j' || ch == KEY_DOWN) && pos < (int)items.size() - 1) pos++;
        else if ((ch == 'k' || ch == KEY_UP) && pos > 0) pos--;
    }

    endwin();  // Exit ncurses mode
    return 0;
}
