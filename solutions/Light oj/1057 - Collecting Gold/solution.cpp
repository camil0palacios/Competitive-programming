#include <bits/stdc++.h>
using namespace std;

int n, m, dp[(1<<16)+10][17];

int dist(deque<pair<int,int> > & v, int a, int b){
    int x1 = v[a].first, x2 = v[b].first;
    int y1 = v[a].second, y2 = v[b].second;
    return max(abs(x1-x2),abs(y1-y2));
}

int go(deque<pair<int,int> > & v, int mask, int last){
    if(mask == (1 << v.size())-1)return dp[mask][last] = dist(v,last,0);
    if(dp[mask][last] != -1)return dp[mask][last];
    int ans = 1e9;
    for(int i = 0; i < v.size(); i++){
        if(((mask >> i)&1) == 0){
            ans = min(ans, go(v,mask|(1<<i),i) + dist(v,last,i));
        }
    }
    return dp[mask][last] = ans;
}

void solve(){
    cin >> n >> m;
    deque<pair<int,int> > v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == 'x')v.push_front({i,j});
            else if(c == 'g')v.push_back({i,j});
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(v,1,0) << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}