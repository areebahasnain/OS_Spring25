#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool isNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && !(i == 0 && str[i] == '-')) {
            return false;
        }
    }
    return true;
}

int findMissingElement(const vector<int>& numbers) {
    int n = numbers.size();
    int totalSum = (n + 1) * (numbers.front() + numbers.back()) / 2;
    int actualSum = 0;
    for (int num : numbers) {
        actualSum += num;
    }
    return totalSum - actualSum;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Error: Please provide at least two integers in a sequence." << endl;
        return 1;
    }

    vector<int> numbers;
    for (int i = 1; i < argc; i++) {
        numbers.push_back(stoi(argv[i]));
    }

    sort(numbers.begin(), numbers.end());
    int missingElement = findMissingElement(numbers);

    ofstream outFile("missing.txt");
    if (!outFile) {
        cerr << "Error: Could not open file to write." << endl;
        return 1;
    }
    outFile << "Missing Element: " << missingElement << endl;
    outFile.close();

    cout << "Missing element written to missing.txt" << endl;
    return 0;
}

