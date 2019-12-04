#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100000];

ll a, b, c, d, e, f;
ll fn( ll n ) {
    if( n == 0 ) {
    	//cout << "i am in a " << endl;
        dp[0] = a;
        return dp[0];
    }
    if( n == 1 ) {
    	    //cout << "i am in b " << endl;
        dp[1] = b;
        return dp[1];
    }
    if( n == 2 ) {
    	    //	cout << "i am in c" << endl;

         dp[2] = c;
        return dp[2];
    }
    if( n == 3 ) {
    	    //	cout << "i am in d " << endl;

         dp[3] = d;
        return dp[3];
    }
    if( n == 4 ) {
    	//cout << "i am in e " << endl;
         dp[4] = e;
        return dp[4];
    }
    if( n == 5 ) {
    //	cout << "i am in f " << endl;
         dp[5] = f;
        return dp[5];
    }
    if(dp[n] != -1)return dp[n];
    dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
    return dp[n];
}
int main() {
    ll n, caseno = 0, cases;
    cin >> cases;
    while( cases-- ) {
        cin >> a >> b >> c >> d >> e >> f >> n;
        for(int i = 0; i < n+10; i++){
        	dp[i] = -1;
        }
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}