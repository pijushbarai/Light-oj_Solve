#include <bits/stdc++.h>
using namespace std;

void Sorting_angle(std::pair<double, double>point[] , int n){
	pair<double, double >temp;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j < n; j++){
			double slovei = ((point[0].second - point[i].second)/(point[0].first - point[i].first));
			double slovej = ((point[0].second - point[j].second)/(point[0].first - point[j].first));
			if(slovei > slovej){
				temp = point[i];
				point[i] = point[j];
				point[j] = temp;
			}
		}
	}
	//---printing for checking---??
	for(int i = 0; i < n; i++){
            cout << i << " = " << point[i].first << " " << point[i].second << endl;
        }
	
}

int main()
{
    int test, t = 0, n;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        pair<double , double>point[n];
        for(int i = 0; i < n; i++){
            cin >> point[i].first;
            cin >> point[i].second;
        }
        //----printing pair---->>
        /*for(int i = 0; i < n; i++){
            cout << i << " = " << point[i].first << " " << point[i].second << endl;
        }*/


        //=-----sort pair finding starting point----=
        sort(point,point+n);
        //for(int i = 0; i < n; i++){
           // cout << i << " = " << point[i].first << " " << point[i].second << endl;
        //}
        
        //sorting with angel
        Sorting_angle(point,n);
        
    }

    return 0;
}