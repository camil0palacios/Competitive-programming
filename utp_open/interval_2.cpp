#include <bits/stdc++.h>
using namespace std;

int main(){
	
	/*
	set<int> myset;
	myset.insert(4);
	myset.insert(4);
	myset.insert(4);
	myset.insert(4);
	//myset.insert(8);
	//myset.insert(1);

	int a=5;
	std::set<int>::iterator itup,itlow;
	itlow = myset.lower_bound (a); // si esta en el arbol o no me devuelve el mismo               
  	itup = myset.upper_bound (a); // si no hay uno mayor a el devuelve el tamaño del arbol
  	--itlow;
  	cout<<*itlow<<endl;
  	cout<<*itup<<endl;
  	if(*itlow < a)cout<<*itlow<<" ";
  	else cout<<-1<<" ";
  	if(*itup != myset.size())cout<<*itup<<endl;
  	else cout<<100001<<endl;
  	
  	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    	std::cout << ' ' << *it;
  	std::cout << '\n';
	*/
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,l,q,a,b;
		cin>>n;
		set<int> lista;
		unordered_map<int,int> exist;
		for(int i=0; i < n; i++){
			cin>>l;
			if(exist.find(l)!= exist.end())exist[l]++;
			else{
				lista.insert(l);
				exist.insert({l,1});
			}
		}
		cin>>q;
		while(q--){
			cin>>a>>b;
			if(a == 1){
				std::set<int>::iterator itlow,itup;
				itlow=lista.lower_bound (b);                
  				itup=lista.upper_bound (b);
  				--itlow;
  				if(*itlow < b && exist.find(*itlow) != exist.end())cout<<*itlow<<" ";
  				else cout<<-1<<" ";
  				if(*itup > b && exist.find(*itup) != exist.end())cout<<*itup<<'\n';
  				else cout<<	100001 <<'\n';
			}
			if(a == 2){
				if(exist.find(b)!=exist.end())exist[b]++;
				else{
					lista.insert(b);
					exist.insert({b,1});
				}
			}
			if(a == 3){
				if(exist.find(b)!= exist.end()){
					exist[b]--;
					if(exist[b]==0){
						exist.erase(b);
						lista.erase(b);
					}
				}

			}
		}

	}

	return 0;
}