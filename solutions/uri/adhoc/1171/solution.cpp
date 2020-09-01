#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,tmp;
	cin>>n;
	unordered_map<int,int> map;
	vector<int> v;
	while(n--){
		cin>>tmp;
		if(map.find(tmp) != map.end())map[tmp]++;
		else {
			map.insert({tmp,1});
			v.push_back(tmp);
		}
	}
	sort(v.begin(),v.end());
	for(auto &i: v)
		cout<<i<<" aparece "<<map[i]<<" vez(es)"<<endl;
	return 0;
}