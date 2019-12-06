#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, t = 0;
    int p1,q1,p2,q2,x,y;
    int cow;
    cin >> test;
    while(test--){
        cin >> p1 >> q1 >> p2 >> q2;
        t++;
        cin >> cow;
        cout << "Case " << t << ":" << endl;
        while(cow--){
            cin >> x >> y;
            if((x >= p1 ) && (x <= p2) && (y >= q1) && (y <= q2)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}