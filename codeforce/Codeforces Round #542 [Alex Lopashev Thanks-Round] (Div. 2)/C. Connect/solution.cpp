#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> used;
vector<pair<int,int>> p1, p2;
int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};

void dfs(vector<string> & v, int r1, int c1, bool f){
    if(f)p1.emplace_back(r1,c1);
    else p2.emplace_back(r1,c1);
    used[r1][c1] = 1;
    for(int i = 0; i < 4; i++){
        int x = r1 + dx[i], y = c1 + dy[i];
        if(x >= 0 && x < v.size() && y >= 0 && y < v.size() && v[x][y] != '1' && !used[x][y]){
            dfs(v,x,y,f);
        }
    }
}

int main(){

    int n, r1, c1, r2, c2;
    while(cin >> n){
        cin >> r1 >> c1 >> r2 >> c2;
        vector<string> v(n);
        used.assign(n, vector<bool> (n,0));
        p1.clear(), p2.clear();
        for(auto &i : v)cin >> i;
        dfs(v,r1-1,c1-1,0);
        if(used[r2-1][c2-1]){
            cout << 0 << endl;
        }else{
            dfs(v,r2-1,c2-1,1);
            int ans = 10000000;
            for(int i = 0; i < p1.size(); i++){
                int x1 = p1[i].first, y1 = p1[i].second;
                for(int j = 0; j < p2.size(); j++){
                    int x2 = p2[j].first, y2 = p2[j].second;
                    ans = min(ans, (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
                }
            }
            cout << ans << endl;
        }
        
    }
    return 0;   
}