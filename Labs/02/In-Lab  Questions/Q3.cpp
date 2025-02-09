#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if at least one integer is provided
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <int1> <int2> <int3> ..." << endl;
        return 1;
    }

    vector<int> numbers;

    // Convert command-line arguments to integers and store in vector
    for (int i = 1; i < argc; i++) {
        numbers.push_back(atoi(argv[i])); // Convert string to int
    }

    // Sort the numbers in ascending order
    sort(numbers.begin(), numbers.end());

    // Print the sorted numbers
    cout << "Sorted numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
