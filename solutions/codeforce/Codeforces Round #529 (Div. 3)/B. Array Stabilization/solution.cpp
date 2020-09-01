#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<int> v(n);
        for(auto &i : v)cin >> i;
        sort(v.begin(), v.end());
        cout << min(v[n-2] - v[0], v[n-1] - v[1]) << endl;
    }
    return 0;
}