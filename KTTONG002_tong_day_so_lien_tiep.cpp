#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	cin >>t;
	while (t--) {
		long long l, r, n;
		cin >>l >>r;
		long long tong=0;
		n=(r-l)+1;
		tong=(r+l)*n/2;
		cout <<tong<<endl;
	}
return 0;
}