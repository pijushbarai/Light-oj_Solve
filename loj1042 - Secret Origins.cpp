#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	int test, t = 0;
	ll n;
	scanf("%d",&test);
	while(test--){
		t++;
		scanf("%lld",&n);
		for(int i = 0; ;i++){
			if((n& (1 << i)) && !(n&(1 << i+1))){
				n = n^(1 << i);
				n = n^(1 << i+1);
				//cout << n << " ch " << i << endl;
				for(int j = i-1; j > 0; j--){
					//cout << "i am in" << endl;
					if((n& (1 << j)) && !(n&(1 << j-1))){
						//cout << n << " ch2" << endl;
						n = n^(1 << j);
						n = n^(1 << j-1);
					}
				}
				break;
			}
		}
		//cout <<"Case " << t << ": "<<  n << endl;
		printf("Case %d: %lld\n", t, n);
	//	cout << "Case " << t << ": " << n << endl;
	
	}
	return  0;
}