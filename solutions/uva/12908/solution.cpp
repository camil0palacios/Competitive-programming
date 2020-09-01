#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int binary_search(long long base,long long l, long long h){
	if(l == h)return (l + h)/2;
	long long mid = (l + h)/2;
	long long sum = (mid*(mid+1))/2;
	if(sum == base)return mid;
	else if(sum > base) return binary_search(base,l,mid);
	else return binary_search(base,mid+1, h); 
}


int main(){
	
	long long s;
	while(cin>>s && s){
		long long n = binary_search(s,1,s);
		long long sum =  (n*(n+1))/2;
		if(sum - s == 0)cout << n+1 <<" "<< n+1 <<endl;
		else cout<< sum - s <<" "<< n <<endl;
	}

	return 0;
}