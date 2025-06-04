#include "ui.h"
#include "explorer.h"
#include <ncurses.h>
#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>
#include <unistd.h>

int runUI() {
    std::string currentPath = ".";

    while (true) {
        std::vector<std::string> items = listDirectory(currentPath);

        std::cout << "Current path: " << currentPath << "\n";
        std::cout << "Contents:\n";

        for (const auto& name : items) {
            std::cout << "  " << name << "\n";
        }

        std::cout << "\nType folder name to go into (or `..` to go back, `q` to quit): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") break;
        if (input == "..") {
            size_t slash = currentPath.find_last_of('/');
            if (slash != std::string::npos) {
                currentPath = currentPath.substr(0, slash);
                if (currentPath.empty()) currentPath = ".";
            }
            continue;
        }

        std::string nextPath = currentPath + "/" + input;
        DIR* dir = opendir(nextPath.c_str());
        if (dir) {
            closedir(dir);
            currentPath = nextPath;
        } else {
            std::cout << "❌ '" << input << "' is not a valid directory.\n";
        }

        std::cout << "\n";
    }

    return 0;
}
