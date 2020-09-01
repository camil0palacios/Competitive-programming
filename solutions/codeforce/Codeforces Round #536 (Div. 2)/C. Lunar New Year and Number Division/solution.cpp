#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<long long> v(n);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        int l = 0, r = n-1;
        long long sum = 0;
        while(l < r){
            sum += (v[l] + v[r])*(v[l] + v[r]);
            l++; r--; 
        }
        cout << sum << endl;
    }
    return 0;
}