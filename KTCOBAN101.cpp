#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int arr[10] = {0};
        long long a,b;
        cin >> a >> b;
        if(a>b){
            int c=a;
            a=b;
            b=c;
        }
        if(a==0)arr[0]++;
        for(int i=a; i<=b; i++){
            long long tl=i;
            while(tl>0){
                int temp=tl%10;
                arr[temp]++;
                tl/10;
            }
        }
        for(int i=0; i<10; i++){
            cout << arr[i] << " ";
            arr[i]=0;
        }
        cout << endl;
    }
}