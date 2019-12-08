#include <bits/stdc++.h>
using namespace std;
#define sz 1000000

string str[sz];

int main()
{
    int test, t = 0, r, x, y;
    int m, n;
    cin >> test;
    while (test--)
    {

        //input-----input----input
        cin >> m >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        // finding starting position---finding starting position
        for(int i = 0, r = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(str[i][j] == '@'){
                    x = i;
                    y = j;
                    r = 1;
                    break;
                }
                if(r == 1)break;

            }
        }
        cout << x <<"  " <<  y << endl;
    }
    
    //input test----input test---input test
    /*for(int i = 0; i < n; i++){
        cout << str[i] << endl;
    }*/

    return 0;
    
}