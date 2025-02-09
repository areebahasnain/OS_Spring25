#include "LetterCount.h"
#include <fstream>
#include <cctype>

int LetterCount::countLetters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return -1;

    char ch;
    int count = 0;
    while (file.get(ch)) {
        if (std::isalpha(ch)) count++;
    }
    return count;
}
