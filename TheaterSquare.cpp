#include <bits/stdc++.h>
using namespace std;

int main()
{
   long long  int n, m, a;
    cin >> n >> m>> a;
   long long  int p, q;
    if(n%a == 0){
        p = n/a;
    }else p = n/a + 1;
    if(m%a == 0){
        q = m/a;
    }else q = m/a + 1;

    cout << p*q << endl;

    return 0;
}