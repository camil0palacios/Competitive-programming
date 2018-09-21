#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,x,y;
	cin>>n;
	vector<pair<int,int>> vec;
	vector<double> res;
	while(n--){
		cin>>x>>y;
		for(auto i: vec){
			res.push_back( sqrt( (i.first - x)*(i.first - x) + (i.second - y)*(i.second - y) ) );
		}
		pair<double,double> aux(x,y);
		vec.push_back(aux);
	}
	sort(res.begin(),res.end());
	printf("%.9f\n",res[0]);
	return 0;
}