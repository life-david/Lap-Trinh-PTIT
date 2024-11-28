#include <bits/stdc++.h>
using namespace std;

// Function to check if a string is a palindrome
bool Ktdoixung(string n) {
    for (int i = 0; i < n.size() / 2; i++)
        if (n[i] != n[n.size() - 1 - i])
            return false;
    return true;
}

// Function to convert a number to a string
string NUM_to_String(long long num) {
    if (num == 0) 
        return "0";
    string Snum = "";
    while (num > 0) {
        Snum = char((num % 10) + '0') + Snum; // Append digits to the front
        num /= 10;
    }
    return Snum;
}

// Function to find the nearest palindrome numbers
void Sodoixunggannhat(long long num) {
    long long Num1 = num - 1;
    while (!Ktdoixung(NUM_to_String(Num1)))
        Num1--;
    
    long long Num2 = num + 1;
    while (!Ktdoixung(NUM_to_String(Num2)))
        Num2++;
    
    if (abs(num - Num1) > abs(num - Num2)) 
        cout << Num2;
    else if (abs(num - Num1) < abs(num - Num2)) 
        cout << Num1;
    else 
        cout << Num1 << " " << Num2; // If both are equidistant
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long sum;
        cin >> sum;
        if (Ktdoixung(NUM_to_String(sum))) {
            cout << sum;
        } else if (sum <= 9) { // Directly print single-digit numbers
            cout << sum;
        } else {
            Sodoixunggannhat(sum);
        }
        cout << endl;
    }
    return 0;
}
