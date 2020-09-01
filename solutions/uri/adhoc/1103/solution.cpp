#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int x1,y1,x2,y2,min1,min2;
	while(true){
		cin>>x1>>y1>>x2>>y2;
		if( x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)break;

		if(x1 == 0)min1= 24*60 + y1;
		else min1 = x1*60 + y1;

		if(x2 == 0)min2 = 24*60 + y2;
		else min2 = x2*60 + y2;
		
		if(min2 > min1)cout<<min2-min1<<endl;
		else cout<<24*60-(min1-min2)<<endl;
	}
	return 0;
}