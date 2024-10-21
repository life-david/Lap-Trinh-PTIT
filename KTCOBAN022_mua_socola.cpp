#include <iostream>
using namespace std;
int sluong_max(){
    int x,y,m,a1,a2,a3;
    cin >> x >> y >> m;
    a1 = m/x;
    a2 = a1;
    while(a2 >= y){
        a3 = a2 / y;
        a1 = a1 + a3;
        a2 = a2%y + a3;
    }
    return a1;
}

int main(){
    int a,d;
    cin >> a;
    for(int i = 0; i < a ;i++){
        d= sluong_max();
        cout << d << endl;
    }
    return 0;
}