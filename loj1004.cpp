#include <bits/stdc++.h>
using namespace std;
#define sz 110

int banana[sz][sz];

int main()
{
    int test, t = 0, n;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        
        //input---- input----input--
        for(int i = 0; i <(2*n); i++){
        	if(i < n){
        		 for(int j = 0; j <= i; j++){
                	cin >> banana[i][j];
        		 }
        	}
           
            else{
                for(int j = 0; j < (2*n-1) - i; j++){
                    cin >> banana[i][j];
                }
            }
        }
		//printing for check--- printing for check----
        /*for(int i = 0; i < (2*n-1) ; i++){
            for(int j = 0; j < n; j++){
                cout << banana[i][j] << " ";
            }
            cout << endl;
        }*/


//prcessing -----precessing----processing
        for(int i = 1; i <(2*n-1); i++){
        	if(i < n){
        		 for(int j = 0; j <= i; j++){
                	if(j == 0){
                        banana[i][j] = banana[i-1][j] + baanana[i][j];
                    }
                    else{
                        banana[i][j] = max(banana[i-1][j],banana[i-1][j-1]) + banana[i][j];
                    }
        		 }
        	}
           
            else{
                for(int j = 0; j < (2*n - 1) - i; j++){
                   banana[i][j] = max(banana[i-1][j],banana[i-1][j+1]) + banana[i][j];
                }
            }
        }
	//cout << endl << endl;
        
	//printing for check--- printing for check----
       /* for(int i = 0; i < (2*n-1) ; i++){
            for(int j = 0; j < n; j++){
                cout << banana[i][j] << " ";
            }
            cout << endl;
        }*/
        cout << "Case " << t << ": " << banana[2*n-2][0] << endl;

    }
    
    return 0;
}