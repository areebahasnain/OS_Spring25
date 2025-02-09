#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c) && c != '-') {
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

int main() {
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    vector<int> numbers;
    string value;
    while (inFile >> value) {
        numbers.push_back(stoi(value));
    }
    inFile.close();

    if (numbers.size() < 2) {
        cerr << "Error: Not enough numbers in the file to determine a missing element." << endl;
        return 1;
    }

    sort(numbers.begin(), numbers.end());
    int missingElement = findMissingElement(numbers);

    ofstream outFile("missing.txt");
    if (!outFile) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }
    outFile << "Missing Element: " << missingElement << endl;
    outFile.close();

    cout << "Missing element written to missing.txt" << endl;
    return 0;
}
