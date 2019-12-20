#include <bits/stdc++.h>
using namespace std;


int subset[2876][2456];
int arr[110], freq[110];

int main()
{
    int test, t = 0, n, sum ;
    cin >> test;

    while(test--){
    	memset(subset, 0, sizeof(subset[0][0]) * 2876 * 2456);
        t++;
        cin >> n >> sum;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            cin >> freq[i];
            
        }
    	

        subset[arr[0]][0] = 1;
        for(int i = 1; i <= freq[0]; i++){
        	subset[arr[0]][arr[0]*i] = 1;
        }
        //for(int i = 0; i <= sum; i++)cout << subset[arr[0]][i] << " " ;
        //cout << endl;
        
        for(int i = 1; i < n; i++){
             for(int j = 0; j <= sum; j++){
             	subset[arr[i]][j] = subset[arr[i-1]][j]%100000007;
             	for(int k = 1; k <= freq[i]; k++){
             		if((j - arr[i]*k) >= 0){
             			subset[arr[i]][j] =  (subset[arr[i]][j] + subset[arr[i-1]][j- arr[i]*k])%100000007;
             		}/*else{
             			int m = max(subset[arr[i]][j],subset[arr[i-1]][j]);
             			subset[arr[i]][j] = m;
             		}*/
             	}
          	}
            
        }
        
        //printing
       /*for(int i =0; i < n; i++){
        	for(int j = 0; j <= sum ; j++){
        		cout << subset[arr[i]][j] << " ";
        	}cout << endl;
        }*/
        
        cout << "Case " << t << ": " << subset[arr[n-1]][sum] << endl;
       
    

    }
   
    return 0;
}