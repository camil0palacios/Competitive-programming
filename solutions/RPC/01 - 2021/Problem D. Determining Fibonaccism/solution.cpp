#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const long long mod = 2147483647;
const int maxN = 10000;
vector<long long> fib(maxN+1);
set<int> T;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	fib[0] = 0,fib[1] = 1;
    T.insert(0);
    // fib[0] = fib[1] = 1;
	T.insert(1);
	for(int i=2; i<=maxN; i++){
		fib[i] = (fib[i-1] + fib[i-2]) % mod;
		T.insert(fib[i]);
	}

	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		n %= mod;
		if(T.find(n) != T.end())
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
}