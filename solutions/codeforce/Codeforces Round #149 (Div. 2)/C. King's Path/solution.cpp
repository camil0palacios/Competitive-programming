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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

const int Mxn = 1e5 + 5;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, y, x1, y1;
    cin >> x >> y >> x1 >> y1 >> n;
    map<ii, int> m;
    fori(i,0,n) {
        int r, a, b;
        cin >> r >> a >> b;
        fore(j,a,b) m[{r, j}] = 1;
    }
    map<ii, int> dist;
    queue<ii> q;
    q.emplace(x, y);
    while(!q.empty()) {
        x = q.front().ft;
        y = q.front().sd;
        q.pop();
        if(x == x1 && y == y1) break;
        fori(i,0,8) {
            int mx = x + dx[i], my = y + dy[i];
            if(m.count({mx, my}) && (!dist.count({mx, my}) || dist[{x, y}]+1 < dist[{mx, my}])) {
                dist[{mx, my}] = dist[{x, y}] + 1;
                q.emplace(mx, my);
            }
        }
    }
    int ans = dist.count({x1, y1}) ? dist[{x1, y1}] : -1;
    cout << ans << endl;
    return 0; 
}