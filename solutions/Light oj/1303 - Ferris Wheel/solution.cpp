#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    bool vis[n][m];
    map<int,int> fw;
    deque<pair<int,bool> > q(n);
    for(int i = 0; i < n; i++){
        q[i].first = i;
        q[i].second = 1;
    }
    memset(vis, 0, sizeof vis);
    int pos = 0, cnt = n*m, ans = 0;
    while(true){
        if(fw.count(pos)){
            vis[fw[pos]][pos] = 1;
            q.push_back({fw[pos],1});
            fw.erase(pos);
            cnt--;
        }
        for(auto & i: q){
            if(i.second && !vis[i.first][pos]){
                fw[pos] = i.first;
                i.second = 0;
                break;
            }
        }
        while(q.size() && !q.front().second)q.pop_front();
        pos = (pos + 1) % m;
        ans += 5;
        if(cnt == 0)break;
    }
    cout << ans << endl;
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