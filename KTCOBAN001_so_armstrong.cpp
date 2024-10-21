// so amstrong la so ma luy thua voi so chu so cua cac chu so cua no bang chinh no
// VD: 153 = 1^3 + 5^3 + 3^3
#include <iostream>
#include <cmath>
using namespace std;

// Ham check so Amstrong 
bool check(int n){
    int sobandau = n;
    int sum = 0;
    int chuso = 0;
    // Dem so chu so cua n
    int temp = n;
    while (temp > 0){
        temp /= 10;
        chuso++;
    }
    // Tinh tong luy thua cua cac chu so
    temp = n;
    while (temp>0){
        int chu_so = temp % 10;
        sum += pow(chu_so,chuso);
        temp /= 10;
    }
    // Kiem tra xem tong co bang voi so ban dau
    return sum == sobandau;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (check(n)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}