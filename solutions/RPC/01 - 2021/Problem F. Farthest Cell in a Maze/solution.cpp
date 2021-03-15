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
typedef vector<ll> vll;

// d l r u
int dir[4] = {'D', 'L', 'R', 'U'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

const int oo = 1e9;
const int Mxn = 1010;
string a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(cs,1,t) {
        int n, m;
        cin >> n >> m;
        swap(n, m);
        int si, sj;
        fori(i,0,n) {
            cin >> a[i];
            fori(j,0,m) if(a[i][j] == '@') si = i, sj = j;
        }
        vector<vi> dist(n, vi(m, oo));
        vector<vector<char>> path(n, vector<char>(m));
        vector<vii> p(n, vii(m));
        queue<ii> q;
        q.emplace(si, sj);
        dist[si][sj] = 0;
        while(!q.empty()) {
            int x = q.front().ft;
            int y = q.front().sd;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if(mx >= 0 && mx < n && my >= 0 && my < m && a[x][y] != '#' 
                    && dist[x][y] < dist[mx][my]) {
                    path[mx][my] = dir[i];
                    p[mx][my] = {x, y};
                    dist[mx][my] = dist[x][y] + 1;
                    q.emplace(mx, my);
                }
            }
        }
        ii mx = {-1, -oo};
        vii far;
        fori(i,0,n) fori(j,0,m) {
            if(a[i][j] == '#') continue;
            if(dist[i][j] != oo && mx.sd < dist[i][j]) {
                mx = {1, dist[i][j]};
                far.clear();
                far.eb(i, j);
            }
            else if(dist[i][j] == mx.sd) {
                mx.ft++;
                far.eb(i, j);
            }
        }
        vector<string> ans;
        fori(i,0,sz(far)) {
            int x = far[i].ft, y = far[i].sd;
            string t;
            while(x != si || y != sj) {
                t += path[x][y];
                int tx = p[x][y].ft, ty = p[x][y].sd;
                x = tx, y = ty;
            }
            reverse(all(t));
            ans.eb(t);
        }
        sort(all(ans));
        cout << "Case " << cs << ':' << endl;
        cout << mx.ft << ' ' << mx.sd << endl;
        for(auto & s : ans) cout << s << endl;
    }
    return 0; 
}