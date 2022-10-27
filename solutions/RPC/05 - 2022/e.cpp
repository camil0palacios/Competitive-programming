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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int oo = 1e9;
const int N = 55;
int a[N][N];
int dist[N][N];
ii pos[110];

struct node {
    int x, y, w;
    node() {}
    node(int x, int y, int w): x(x), y(y), w(w) {}
    bool operator<(const node & n) const {
        return w > n.w;
    }
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, f, s;
    cin >> n >> m >> f >> s;
    fori(i,0,s)  {
        int x, y;
        cin >> x >> y;
        x--, y--;
        pos[i].ft = x;
        pos[i].sd = y;
    }
    pos[s].ft = n-1, pos[s].sd = m-1;
    fori(i,0,n) fori(j,0,m) dist[i][j] = oo;
    priority_queue<node> q;
    q.emplace(0, 0, 0);
    dist[0][0] = 0;
    while(!q.empty()) {
        int x = q.top().x;
        int y = q.top().y;
        int w = q.top().w;
        q.pop();
        if(w != dist[x][y]) continue;
        fore(i,0,s) {
            int mx = pos[i].ft, my = pos[i].sd;
            int d = abs(x - mx) + abs(y - my);
            if(d <= f && dist[x][y] + d < dist[mx][my]) {
                dist[mx][my] = dist[x][y] + d;
                q.emplace(mx, my, dist[mx][my]);
            }
        }
    }
    cout << dist[n-1][m-1] << endl;
    return 0; 
}