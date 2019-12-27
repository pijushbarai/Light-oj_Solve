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
int orientation(pair<d,d>p1,pair<d,d>p2,pair<d,d>p3){
	//	cout << "P1 = " <<p1.first << " " << p1.second << endl;
	//	cout << "P2 = " <<p2.first << " " << p2.second << endl;
	//	cout << "P3 = " <<p3.first << " " << p3.second << endl;
	d value = ((p1.second-p2.second)*(p2.first - p3.first) - (p1.first-p2.first)*(p2.second - p3.second)); 
	
	if(value < 0){
		hull.push(p2);
		hull.push(p3);
	}else if(value == 0){
		d x = distance(p1,p2);
		d y = distance(p1,p3);
		if(x > y){
			hull.push(p2);
		}else{
			hull.push(p3);
		}
		
	}else{
		return -1;
	}
    return 0;
}


void convex_hull(std::pair<d , d>point[], int n){
	hull.push(point[0]);
	hull.push(point[1]);
    pair<d , d> p1,p2,p3;
	for(int i = 2; i < n; i++){
		
		p2 = hull.top();
		hull.pop();
		p1 = hull.top();
		p3 = point[i];
		int x = orientation(p1,p2,p3);
        i = i + x;
		
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
				}
			}
			
		}
	}
	//---printing for checking---??
	//cout << "-------------" << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << i << " = " << point[i].first << " " << point[i].second << endl;
	// }
	
}


int main()
{
    int test = 1, t = 0, n, j;
    d a, b, c, q, r;
    pair <d,d>key;
    //freopen("input.txt","r",stdin);
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
        //----PRINTING PAIR---->>
       
       // COUT << "INITIAL = " << INITIAL.FIRST << " " << INITIAL.SECOND << ENDL;
       


        //-------sorting with angel------
        Sorting_angle(point,n );
        convex_hull(point,n);
        //  for(int i  = 0; i < n; i++){
        // 	cout << point[i].first << " " << point[i].second << endl;
        // }
        
        //cout << "Hull size = " << hull.size() << endl;
       // pair<d,d>ch,dhorerakhi = hull.top();
        //d sum = 0;
        pair<d,d>ch, fst,p1, cnt, p2;
        
     /* while(!hull.empty()){
        	ch = hull.top();
			cout << ch.first << " " << ch.second << endl;
            hull.pop();
        }*/
        d m  = 1289988;
        fst = hull.top();
        p1 = fst;
        hull.pop();
        cnt = hull.top();
        hull.top();
        
        while(!hull.empty()){
        	p2 = hull.top();
        	a = distance(p1,cnt);
        	b = distance(p2, cnt);
        	c = distance(p1, p2);
        	q = (pow(a, 2) + pow(b, 2) - pow(c,2));
        	r = 2*a*b;
        	d angle = acos(q/r);
        	if(angle < m){
        		m = angle;
        	}
        	hull.pop();
        	p1 = cnt;
        	cnt = p2;
        }
        p2 = fst;
    
        a = distance(p1,cnt);
       	b = distance(p2, cnt);
       	c = distance (p1,p2);
       	q = (pow(a, 2) + pow(b, 2) - pow(c,2));
       	r = 2*a*b;
       	d angle = acos(q/r);
       	if(angle < m){
       		m = angle;
       	}
        
        cout << angle << endl;
        
    }

    return 0;
}