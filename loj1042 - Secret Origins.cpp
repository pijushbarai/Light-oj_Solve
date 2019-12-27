#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll find_next(ll n, ll no1){
	int x = 0;
	while(true){
		n++;
		int l = ceil(log2(n));
		for(int i = 0; i < l; i++){
			if(n & (1 << i)){
				x++;
			}
		}if(x == no1){
			return n;
		}
		x = 0;
	}
}

int main()
{
	int test, t = 0;
	ll n;
	cin >> test;
	while(test--){
		t++;
		cin >> n;
		int no1 = 0;
		ll l = ceil(log2(n)); 
		for(int i = 0; i < l; i++){
			if(n & (1 << i)){
				no1++;
			}
		}
		ll ans = find_next(n, no1);
		cout << "Case " << t << ": " << ans << endl;
		
	}
	return  0;
}