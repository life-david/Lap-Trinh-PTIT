#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream infile("bignumber.in");
    ofstream outfile("bignumber.out");

    if (!infile || !outfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int num_operations;
    infile >> num_operations;
    infile.ignore();  // Ignore newline character after the number

    string line;
    while (num_operations--) {
        getline(infile, line);
        stringstream ss(line);
        int num1, num2;
        char op;
        ss >> num1 >> op >> num2;

        if (op == '+') {
            outfile << (num1 + num2) << endl;
        } else if (op == '*') {
            outfile << (num1 * num2) << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}