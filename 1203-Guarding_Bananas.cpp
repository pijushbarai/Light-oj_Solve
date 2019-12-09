#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test, t = 0, n;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        pair<int , int>point[n];
        for(int i = 0; i < n; i++){
            cin >> point[i].first;
            cin >> point[i].second;
        }
        //----printing pair---->>
        /*for(int i = 0; i < n; i++){
            cout << i << " = " << point[i].first << " " << point[i].second << endl;
        }*/


        //=-----sortpair----=
        sort(point,point+n);
        for(int i = 0; i < n; i++){
            cout << i << " = " << point[i].first << " " << point[i].second << endl;
        
    }

    return 0;
}