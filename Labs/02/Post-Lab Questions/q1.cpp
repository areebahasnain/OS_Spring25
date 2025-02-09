#include <iostream>
#include <vector>

using namespace std;

bool isNumber(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') && !(i == 0 && str[i] == '-')) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Error: No parameters given." << endl;
        return 1;
    }

    vector<int> numbers;
    int sum = 0;

    for (int i = 1; i < argc; i++) {
        int num = stoi(argv[i]);
        numbers.push_back(num);
        sum += num;
    }

    double average = static_cast<double>(sum) / numbers.size();

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}
