#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n;
    while(cin >> n){
        vector<long long> v(n);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        long long cmax = 0, cmin = 0;
        for(int i = 0; v[i] == v[0] && i < n; i++)cmin++;
        for(int i = n-1; v[i] == v[n-1] && i >= 0; i--)cmax++;
        cout << v[n-1] - v[0] << " " << (cmin == n && cmax == n ? n*(n-1)/2 : cmin*cmax) << endl; 
    }
    return 0;
}