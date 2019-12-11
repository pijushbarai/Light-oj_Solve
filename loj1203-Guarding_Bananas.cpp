#include <bits/stdc++.h>
#define d double
#define pi acos(-1)
using namespace std;
 
stack <pair<d,d>>hull;


d find_slove(std:: pair<d, d>point1,std:: pair<d, d>point2){
    return ((point1.second - point2.second)/(point1.first - point2.first));
}

d distance(pair<d,d>p1, pair<d,d>p2){
	return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}
void orientation(pair<d,d>p1,pair<d,d>p2,pair<d,d>p3){
	//	cout << "P1 = " <<p1.first << " " << p1.second << endl;
	//	cout << "P2 = " <<p2.first << " " << p2.second << endl;
	//	cout << "P3 = " <<p3.first << " " << p3.second << endl;
	d slv1 = find_slove(p1,p2);
	d slv2 = find_slove(p2,p3);
	
	if(slv1 < slv2){
		hull.push(p2);
		hull.push(p3);
	}else if(slv1 == slv2){
		d x = distance(p1,p2);
		d y = distance(p1,p3);
		if(x > y){
			hull.push(p2);
		}else{
			hull.push(p3);
		}
		
	}else{
		hull.push(p2);
	}
}


void convex_hull(std::pair<d , d>point[], int n){
	hull.push(point[0]);
	hull.push(point[1]);
	for(int i = 2; i < n; i++){
		pair<d , d> p1,p2,p3;
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
			}else if(slovei == slovej){
				d s1,s2;
				s1 = distance(point[0],point[i]);
				s2 = distance(point[0],point[j]);
				if(s1 > s2){
					temp = point[i];
					point[i] = point[j];
					point[j] = temp;
				}else{
					temp = point[j];
					point[j] = point[i];
					point[i] = temp;
				}
			}
			
		}
	}
	//---printing for checking---??
	//cout << "-------------" << endl;
	//for(int i = 0; i < n; i++){
	//	cout << i << " = " << point[i].first << " " << point[i].second << endl;
	//}
	
}


int main()
{
    int test, t = 0, n, j;
    pair <d,d>key;
    cin >> test;
    while(test--){
        t++;
        cin >> n;
        pair<d , d>point[n];
        for(int i = 0; i < n; i++){
            cin >> point[i].first;
            cin >> point[i].second;
        	key = point[i];
        	j = i-1;
        	while(j >= 0 && (point[j].first > key.first) ){
        		point[j+1] = point[j];
        		j--;
        	}
        	point[j+1] = key;
        }
        //----printing pair---->>
        //for(int i = 0; i < n; i++){
        //    cout << i << " = " << point[i].first << " " << point[i].second << endl;
        //}
       // cout << "Initial = " << initial.first << " " << initial.second << endl;
       


        //-------sorting with angel------
        Sorting_angle(point,n );
        convex_hull(point,n);
        
        cout << "Hull size = " << hull.size() << endl;
        
      while(!hull.empty()){
        	pair<d,d>ch = hull.top();
        	cout << ch.first << " " << ch.second << endl;
        	hull.pop();
        }
        
        
    }

    return 0;
}