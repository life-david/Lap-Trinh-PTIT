#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t ;
    while(t--){
        string s;
        cin >> s;
        if(s[0] == '-') cout << s.length()-1 << endl ;
        else cout << s.length() << endl;
    }
    return 0;
}