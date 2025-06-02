#include <iostream>
#include <dirent.h>   // Required for DIR, opendir, readdir, closedir
#include <cstring>    // For strerror
#include <errno.h>    // For errno

int main() {
    const char* path = ".";  // Current directory

    DIR* dir = opendir(path); 
    if (dir == nullptr) {
        std::cerr << "Failed to open directory: " << strerror(errno) << '\n';
        return 1;
    }

    std::cout << "Contents of " << path << ":\n";

    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << "  " << entry->d_name << '\n';  // Print each file name
    }

    closedir(dir);  // Always close the directory

    return 0;
}
