#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, t = 0, x, sum = 0;
    cin >> test;
    while(test--){
        t++;
        sum  = 0;
        int p ;
        cin >> p;
        for(int i = 0; i < p; i++){
            cin >> x;
            if(x >= 0)sum  = sum + x;
            
        }
        cout << "Case " << t << ": " << sum << endl;
    }
    return 0;
}