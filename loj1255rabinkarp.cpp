#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000

ll power[1000100];
ll pre[1000100];

int rabinkarp(string text, string pat){
    ll temp,patlen = pat.size();
    //cout << patlen << "pl" << endl;
    ll textlen = text.size();
   // cout << textlen << " tl" << endl;
    ll key = 0, i, k , cnt = 0;

    for(int i = 0; i < patlen; i++){
        k = pat[i]-'a' +1;
        key = (key + (k*power[i])%mod)%mod;
        //cout << key << " key" << endl;
    }
    //cout << key << " key2" << endl;

    pre[0] = 0;
    for(int i = 0; i < textlen;i++){
        k = text[i]-'a'+ 1;
        pre[i+1] = (pre[i]+k*power[i])%mod;
    }
    //for(int i = 0; i <= textlen; i++)cout << pre[i] << " ";
    //cout << endl;
   // cout <<"key = " << key << endl;
   // cout << "patlen = " << patlen << endl;
   // cout << "Textlen = " << textlen << endl;

    for(int i = 0; (i + patlen) <= textlen; i++){
    	//cout << i;
         temp = (pre[i+patlen] - pre[i])%mod;
         //cout << temp << " == " <<  (key*power[i])%mod << endl;
        if(temp == (key*power[i])%mod ){
        	int c = 0, k =0;
        	for(int j = i; j  < i+patlen; j++){
        		if(pat[k] == text[j])c++;
        		k++;
        		//cout << "c = " << c<< endl;
        	}if(c == patlen)cnt++;
        	//cout << " ac i = " << i << endl;
        }
    }
    return cnt;

}


int main()
{
    int test, t = 0;
    cin >> test;
    string text, pat;
    while (test--)
    {      
        cin >> text >> pat;
        ll len = text.size();

        for(int i = 0; i < len; i++){
            power[i] = pow(2,i);
        }  
        t++;
        /*for(int i = 0; i < len; i++){
        	cout << power[i] << endl;
        }*/
        int x = rabinkarp(text,pat);
        cout << "Case " << t << ": " << x << endl;
    }    
    return 0;
}