#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k;
    while(cin >> n >> m >> k){
        vector<long long> v(n);
        for(auto & i: v)cin >> i;
        sort(v.begin(), v.end());
        long long aux = m/(k+1);
        cout << v[n-1]*(m-aux) + v[n-2]*(aux) << endl;
    }
    return 0;
}