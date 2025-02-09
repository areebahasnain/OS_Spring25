#include "LetterCount.h"
#include "WordCount.h"
#include "LineCount.h"
#include <iostream>
using namespace std;

int main() {
    string filename = "text.txt";

    LetterCount lc;
    WordCount wc;
    LineCount lnc;

    cout << "Letters: " << lc.countLetters(filename) << "\n";
    cout << "Words: " << wc.countWords(filename) << "\n";
    cout << "Lines: " << lnc.countLines(filename) << "\n";

    return 0;
}
