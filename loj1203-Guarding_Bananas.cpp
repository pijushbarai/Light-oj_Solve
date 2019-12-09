#include <bits/stdc++.h>
using namespace std;

stack<pair<double, double>>hull;

double find_slove(std:: pair<double, double>point1,std:: pair<double, double>point2){
    return ((point1.second - point2.second)/(point1.first - point2.first));
}

void Sorting_angle(std::pair<double, double>point[] , int n){
	pair<double, double >temp;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j < n; j++){
			double slovei = find_slove(point[0],point[i]);
			double slovej = find_slove(point[0],point[j]);
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

void convex_hull(std::pair<double , double>points, int n){
	hull.push(point[0]);
	hull.push(point[1]);
	for(int i = 2; i < n; i++){
		
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