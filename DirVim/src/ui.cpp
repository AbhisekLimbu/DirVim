#include <ncurses.h>

int runUI() {
    initscr();              // Start ncurses
    noecho();               // Don’t show typed characters
    cbreak();               // Disable line buffering
    keypad(stdscr, TRUE);   // Enable special keys (arrows, etc.)

    int pos = 0;  // Our selection index
    int ch;

    while (true) {
        clear();
        mvprintw(0, 0, "Press 'j' (↓), 'k' (↑), 'q' to quit");

        // Simulated items
        for (int i = 0; i < 5; i++) {
            if (i == pos)
                mvprintw(i + 2, 0, "> Item %d", i + 1);
            else
                mvprintw(i + 2, 2, "Item %d", i + 1);
        }

        ch = getch();

        if (ch == 'q') break;
        else if (ch == 'j' && pos < 4) pos++;
        else if (ch == 'k' && pos > 0) pos--;
    }

    endwin();  // Exit ncurses
    return 0;
}
