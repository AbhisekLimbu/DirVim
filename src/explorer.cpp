#include "explorer.h"
#include <dirent.h>
#include <vector>
#include <string>

std::vector<std::string> listDirectory(const std::string& path) {
    std::vector<std::string> entries;

    DIR* dir = opendir(path.c_str());
    if (!dir) return entries;

    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if (name != ".")  // Skip current dir
            entries.push_back(name);
    }

    closedir(dir);
    return entries;
}
