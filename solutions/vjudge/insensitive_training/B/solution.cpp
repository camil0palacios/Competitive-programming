#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int go(vector<ll> & v, int idx, ll s1, ll s2, ll s3, int a){
    if(idx == (int)v.size()){
        return (s1 == s2 && s2 == s3 && a == 7);
    }
    int ans = go(v, idx + 1, s1 + v[idx], s2, s3, a | (1 << 0));
    ans += go(v, idx + 1, s1, s2 + v[idx], s3, a | (1 << 1));
    ans += go(v, idx + 1, s1, s2, s3 + v[idx], a | (1 << 2));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<ll> v(n);
        for(auto & i : v)cin >> i;
        cout << go(v, 0, 0, 0, 0, 0) << endl;
    }
    return 0;
}