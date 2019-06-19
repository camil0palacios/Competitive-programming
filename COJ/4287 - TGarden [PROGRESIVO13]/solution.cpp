#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct cell{
    int x, y, t;
    cell(){}
    cell(int _x, int _y, int _t): x(_x), y(_y), t(_t){}
    bool operator<(cell & o){
        return x < o.x;
    }
};

int dx[4] = {1,0,-1, 0};
int dy[4] = {0,1, 0,-1};

int bfs(queue<cell> & q, set<pair<int,int>> & vis, int t){
    int ans = 0;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int ct = q.front().t;
        q.pop();
        ans++;
        for(int i = 0; i < 4; i++){
            int mx = x + dx[i], my = y + dy[i];
            if(!vis.count({mx, my}) && ct + 1 <= t){
                q.push(cell(mx, my, ct + 1));
                vis.insert({mx,my});
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t;
    cin >> n >> m >> t;
    queue<cell> q;
    set<pair<int,int>> vis;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        q.push(cell(x,y,0));
        vis.insert({x,y});
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        vis.insert({x,y}); 
    }
    cout << bfs(q, vis, t) << endl;
    return 0;
}