#include <bits/stdc++.h>
using namespace std;

bool ans;

void go(vector<int>& v, int idx = 0, int sum = 0){
    if(idx == v.size()){
        if(sum == 0)ans = 1;
        return;
    }
    int sum_1 = (sum + v[idx] >= 360 ? (sum + v[idx]) - 360 : sum + v[idx]);
    go(v, idx + 1, sum_1);
    int sum_2 = (sum - v[idx] < 0 ? 360 - (sum - v[idx]) : sum - v[idx]);
    go(v, idx + 1, sum_2);
}

int main(){

    int n;
    while(cin >> n){
        ans = 0;
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        go(v);
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}