#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int Mxn = 2005;
int dis[Mxn][Mxn];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, k;
    cin >> n >> m >> k;
    fori(i,0,n) fori(j,0,m) dis[i][j] = oo;
    queue<ii> q;
    fori(i,0,k) {
        int x, y; cin >> x >> y;
        x--, y--;
        q.push({x, y});
        dis[x][y] = 0;
    }
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        fori(i,0,4) {
            int x = p.ft + dx[i], y = p.sd + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && dis[p.ft][p.sd] + 1 < dis[x][y]) {
                dis[x][y] = dis[p.ft][p.sd] + 1;
                q.push({x, y});
            }
        }
    }
    ii ans;
    int x = 0;
    fori(i,0,n) fori(j,0,m) {
        if(x < dis[i][j]) {
            x = dis[i][j];
            ans = {i, j};
        }
    }
    cout << ans.ft + 1 << ' ' << ans.sd + 1 << endl;
    return 0; 
}