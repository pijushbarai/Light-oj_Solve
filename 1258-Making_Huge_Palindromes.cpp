#include <bits/stdc++.h>
using namespace std;
#define sz 1000100

int lps[1000100];

void KMP(string pat){
    int len = pat.size();
    lps[0] = 0;
    int j = 0, i = 1;
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
    for(int i = 0; i < pat.size(); i++)cout << lps[i] << " ";
    cout << endl;

    
}

int srch(string pat, string text){
    int len  = pat.size();
    int i = 0, j = 0;
    while(i < len){
        if(pat[i] == text[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    return j;
}

int main()
{
    string text, pat;
    int test, t = 0,texlen;

    cin >> test;
    while(test--){
        t++;
        cin >> text;
        pat = text;
        texlen = text.size();
        reverse(pat.begin(),pat.end());
        //cout << pat << endl;
        KMP(text);
        int match = srch(pat,text);
        cout << "Case " << t << ": " << (texlen*2)-1- match<< endl;
    }

    return 0;
}