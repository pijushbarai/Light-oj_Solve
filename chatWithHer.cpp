#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    int l = s.length();

    int l2 = l;
    sort(s.begin(),s.end());

    for(int i = 0; i < l;i++){
        if(s[i] == s[i+1])l2--;
    }

    if(l2 % 2 == 0)cout<<"CHAT WITH HER!" <<endl;
    else cout << "IGNORE HIM!" << endl;

    return 0;

}
