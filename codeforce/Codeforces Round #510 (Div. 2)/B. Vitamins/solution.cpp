#include <bits/stdc++.h>
using namespace std;

vector<int> w;
vector<string> v;
int dp[100000][8], inf = 1e5 * 1000 * 3;

int sol(string & s, int mask){
    int x = mask;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' && (x&1) == 0)x |= (1 << 0);
        if(s[i] == 'B' && (x&2) == 0)x |= (1 << 1);
        if(s[i] == 'C' && (x&4) == 0)x |= (1 << 2);
    }
    return x;
}

int go(int i, int mask){
    if(mask == 7)return 0;
    if(i == w.size())return inf;
    if(dp[i][mask] != -1)return dp[i][mask];
    int ans = inf;
    int x = sol(v[i], mask);
    ans = min(ans, go(i+1,x) + w[i]);
    ans = min(ans, go(i+1,mask));
    return dp[i][mask] = ans;
}

int main(){

    int n;
    while(cin >> n){
        w.assign(n,0),
        v.assign(n,"");
        for(int i = 0; i < n; i++){
            cin >> w[i] >> v[i];
        }
        memset(dp, -1, sizeof dp);
        int ans = go(0,0);
        if(ans >= inf)cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}