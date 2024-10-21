#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


float tinhTongDaThuc(float x, int n) {
    double S = 0;
    
    for (int k = 1; k <= n; ++k) {
        double sum_i = 0;
        
        for (int i = 1; i <= k; ++i) {
            sum_i += i;
        }
       
        S += pow(x, k) / sum_i;
    }
    return S;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n;
        float x;
        cin >> n >> x;

        
        cout << fixed << setprecision(3) << tinhTongDaThuc(x, n) << endl;
    }

    return 0;
}