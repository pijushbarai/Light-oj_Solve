#include <bits/stdc++.h>
using namespace std;

int lps[1000100];

void kmp(string pat){
    int len = pat.size();
    int i = 1, j = 0;
    while(i < len){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }

    }

}


int srch(string text, string pat){
    int cnt  = 0;
    int len = text.size();
    int patlen = pat.size();
    int i = 0, j = 0;
    while(i  < len){
        if(text[i] == pat[j]){
            i++;
            j++;
            if(j == patlen){
                cnt++;
            }
        }else{
            if(j != 0){
                j = lps[j-1];
            }else i++;
        }
    }
    return cnt;
}

int main()
{
    int test, t = 0;
    string text, pat;

    cin >> test;
    while(test){
        t++;
        cin >> text >> pat;
        kmp(pat);
        int x = srch(text,pat);
         cout << "Case " << t << ": " << x << endl;
         test--;
         int l = pat.size();
         for(int i = 0; i < l;i++){
        lps[i] = 0;
       }
    }
    return 0;
}