#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if filename is provided
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    // Check if the file exists
    if (!file) {
        cout << "Error: File '" << filename << "' not found!" << endl;
        return 1;
    }

    // Read and print file contents
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
