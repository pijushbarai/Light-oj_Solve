#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, t = 0, cnt = 0;
    int n, temp,temp2, x;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        temp = 2;
        cnt = 0;
        while(n--){
            cin >> x;
            if((x - temp) == 0){
            	temp = x;
            }
            else if((x -temp) <= 5){
            	cnt++;
            	temp = x;
            }
            else{
            	if((x-temp)%5 == 0){
            		cnt  = cnt + (x -temp)/5;
            		temp = x;
            	}else{
            		cnt = cnt + (x - temp)/5 + 1;
            		temp = x;
            	}
            }
            

        }
        cout << "Case " << t << ": " << cnt << endl;
    }
    return 0;
}