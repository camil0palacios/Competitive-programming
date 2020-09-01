#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef pair<int,int> ii;
vector<queue<ii>> q;
vector<int> res;
int cnt;

void solve(vector<vector<int>> &v, vector<long long> &s, int n, int m, int p){
    
    int turn = 1;
    int y[4] = {0,-1,0,1}, x[4] = {-1,0,1,0};
    while(cnt){
        for(int j = 0; !q[turn].empty() && j < s[turn]; j++){
            for(int i = q[turn].size() ; i-- ; ){
                ii p = q[turn].front(); q[turn].pop();
                for(int l = 0; l < 4; l++){
                    int my = p.ff + y[l], mx = p.ss + x[l];
                    if(my >= 0 && my < n && mx >= 0 && mx < m && !v[my][mx]){
                        q[turn].push({my,mx});
                        v[my][mx] = turn;
                        res[turn]++;
                        cnt--;
                    }
                }
            }
        }
        turn++;
        if(turn > p)turn = 1;
        bool f = 1;
        for(int i = 1; i <= p; i++)
            f &= q[i].empty();
        if(f)
            break;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, p;
    while(cin >> n >> m >> p){
        vector<long long> s(p+1);
        for(int i = 1; i <= p ; i++)cin >> s[i];
        vector<vector<int>> v(n,vector<int> (m));
        q.assign(p+1,queue<ii>());
        res.assign(p+1,0);
        cnt = n*m;
        for(int i = 0; i < n; i++){
            string tmp; cin >> tmp;
            for(int j = 0; j < m; j++){
                if(tmp[j] == '.')v[i][j] = 0;
                else if(tmp[j] == '#')v[i][j] = -1, cnt--;
                else{
                    int col = tmp[j] - '0';
                    v[i][j] = col;
                    res[col]++;
                    q[col].push({i,j});
                    cnt--;
                }
            }
        }
        solve(v,s,n,m,p);
        for(int i = 1; i <= p; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;   
}