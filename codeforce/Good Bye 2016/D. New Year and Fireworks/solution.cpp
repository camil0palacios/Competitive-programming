#include <bits/stdc++.h>
using namespace std;

struct node{
    pair<int,int> l, r;
    node(){}
    node(int x1, int y1, int x2, int y2){
        l.first = x1;
        l.second = y1;
        r.first = x2;
        r.second = y2;
    }
};

map<int,pair<int,int>> d = {{90,{135,45}}, {0,{45,315}}, {180,{225,135}}, {270,{315,225}},
                            {45,{90,0}}, {135,{180,90}}, {225,{270,180}}, {315,{0,270}} };
map<int,node> m = { 
    {90,node(-1,1,1,1)}, {0,node(1,1,1,-1)}, {180, node(-1,-1,-1,1)}, {270, node(1,-1,-1,-1)},
    {45, node(0,1,1,0)}, {135,node(-1,0,0,1)}, {225,node(0,-1,-1,0)}, {315,node(1,0,0,-1)} };
set<vector<int>> s;
set<pair<int,int>> cell;
vector<int> v;

int backtrack(int i, int dir, int x, int y){
    if(i == v.size())return 0;
    if(s.count({i,dir,x,y}))return 0;
    s.insert({i,dir,x,y});
    pair<int,int> a = m[dir].l, b = m[dir].r;
    int nx_1 = x, ny_1 = y, nx_2 = x, ny_2 = y, cnt = 0;
    for(int j = 0; j < v[i]; j++){
        nx_1 += a.first, ny_1 += a.second;
        nx_2 += b.first, ny_2 += b.second;
        if(!cell.count({nx_1,ny_1})){
            cnt++;
            cell.insert({nx_1,ny_1});
        }
        if(!cell.count({nx_2,ny_2})){
            cnt++;
            cell.insert({nx_2,ny_2});
        }
    }   
    cnt += backtrack(i+1,d[dir].first,nx_1,ny_1);
    cnt += backtrack(i+1,d[dir].second,nx_2,ny_2);
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        v.assign(n,0);
        s.clear(), cell.clear();
        for(auto & i: v)cin >> i;
        int y = 0;
        for(int i = 0; i < v[0]; i++){
            y++;
            s.insert({0,90,0,y});
            cell.insert({0,y});
        }
        int ans = y + backtrack(1,90,0,y);
        cout << ans << endl;
    }
    return 0;
}