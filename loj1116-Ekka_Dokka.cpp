#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll test, t = 0, n;
    cin >> test;
    test;
    while(test--){
        t++;
        cin >> n;
        if(n%2 == 1){
            cout << "Case " << t << ": " << "Impossible" << endl;
        }else{
            for(int i = 2; i < n; i = i + 2){
                if((n/i)%2 == 1 && (n%i) == 0){
                    cout << "Case " << t << ": " << n/i << " " << i << endl;
                    break;
                }
            }
        }
        
    }
    return 0;
}