#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	int test, t = 0;
	ll n, x = -2, y = -2;
	cin >> test;
	while(test--){
		t++;
		cin >> n;
		int no1 = 0;
		ll l = ceil(log2(n)); 
		
		//===finding the place x and y ====
		for(int i = 1; i < l; i++){
			//cout << "x = " << x << " y = " << y << endl;
			if((n &(1 << i)) == 0 && x < 0 && (n &(1 << i-1)) ){
				x = i;
				y = i-1;
				break;
			}
		}
		
		
		//=====findind===value==in various====condition====
		cout<< endl << endl << "final x = " << x << " final y = " << y << endl;
		if(l == 0){
			n =(n^(1 << 1));
			n =(n^(1 << 0));
			cout << "Case " << t << ": " << n << endl;
		}else if(x == 0 && y < 0){
			n = (1 << l)| (1 << 0);
			cout << "Case " << t << ": " << n << endl;
		}
		else if(x >0 && y >= 0 && (x-y) < 2){
			n = (n ^(1 << x));
			n = (n^(1 << y));
			cout << "Case " << t << ": " << n << endl;
		}else if(x < 0 && y < 0){
			n = (n^(1 << l));
			n = (n^(1 << l-1));
			cout << "Case " << t << ": " << n << endl;
		}else if(x > 0 && y < 0){
			//cout << "l = "<< l << endl;
			//cout << n << " before " << endl;
			n = (n^(1 << l+1));
			//cout << n << " middle " << endl;
			n = (n^(1 << l));
			//cout << n << " end " << endl;
			cout << "Case " << t << ": " << n << endl;
		}else if(x > 0 && y > 0 && (x - y) > 1){
			n = (n^(1 << y+1));
			n = (n^(1 << y));
			cout << "Case " << t << ": " << n << endl;
		}
		x = -2;
		y = -2;
	}
	return  0;
}