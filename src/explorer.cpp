#include "explorer.h"
#include <dirent.h>
#include <vector>
#include <string>

std::vector<std::string> listDirectory(const std::string& path) {
    std::vector<std::string> entries;
    DIR* dir = opendir(path.c_str());
    if (!dir) return entries;

    entries.push_back(".."); // Add parent option

    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if (name == "." || name == "..") continue;
        entries.push_back(name);
    }

    closedir(dir);
    return entries;
}
