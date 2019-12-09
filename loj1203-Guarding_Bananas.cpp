#include <bits/stdc++.h>
#define d double
using namespace std;
 
stack <pair<d,d>>hull;


d find_slove(std:: pair<d, d>point1,std:: pair<d, d>point2){
    return ((point1.second - point2.second)/(point1.first - point2.first));
}

d distance(pair<d,d>p1, pair<d,d>p2){
	return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}
void orientation(pair<d,d>p1,pair<d,d>p2,pair<d,d>p3){
	d s1 = find_slove(p1,p2);
	d s2 = find_slove(p2,p3);
	if(s1 < s2){
		hull.push(p2);
		hull.push(p3);
	}else if(s1 == s2){
		d x = distance(p2,p1);
		d y = distance(p1,p3);
		if(x > y){
			hull.push(p1);
		}else{
			hull.push(p3);
		}
		
	}else{
		
	}
}


void convex_hull(std::pair<d , d>point[], int n){
	hull.push(point[0]);
	hull.push(point[1]);
	for(int i = 2; i < n; i++){
		pair<d, d> p1,p2,p3;
		p2 = hull.top();
		hull.pop();
		p1 = hull.top();
		p3 = point[i];
		orientation(p1,p2,p3);
		
	}
}


//------sorting with angle-----
void Sorting_angle(std::pair<d, d>point[] , int n){
	pair<d, d >temp;
	for(int i = 1; i < n; i++){
		for(int j = i+1; j < n; j++){
			d slovei = find_slove(point[0],point[i]);
			d slovej = find_slove(point[0],point[j]);
			if(slovei > slovej){
				temp = point[i];
				point[i] = point[j];
				point[j] = temp;
			}
			
		}
	}
	//---printing for checking---??
	/*for(int i = 0; i < n; i++){
            cout << i << " = " << point[i].first << " " << point[i].second << endl;
        }*/
	
}

int main()
{
    int test, t = 0, n;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        pair<d , d>point[n];
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
       
//-------sorting with angel------
        Sorting_angle(point,n);
        convex_hull(point,n);
        
      /* while(!hull.empty()){
        	pair<d,d>ch = hull.top();
        	hull.pop();
        	cout << ch.first << " " << ch.second << endl;
        }*/
        cout << hull.size();
        
    }

    return 0;
}