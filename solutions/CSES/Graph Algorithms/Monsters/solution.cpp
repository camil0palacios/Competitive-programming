#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
const int INF = 1e9;
char dir[4] = { 'D', 'R', 'U', 'L'};
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
const int MXN = 1010;
int n, m;
char a[MXN][MXN];
int times[MXN][MXN];
bool vis[MXN][MXN];
vector<ii> mstr;
ii si, fi;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#';
}

void floodfill(vector<ii> & mstr) {
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) times[i][j] = INF;
    queue<ii> q;
    for(auto & p : mstr) {
        q.emplace(p.ft, p.sd);
        times[p.ft][p.sd] = 0;
    }
    while(!q.empty()) {
        int x = q.front().ft;
        int y = q.front().sd;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(check(mx, my) && times[x][y] + 1 < times[mx][my]) {
                times[mx][my] = times[x][y] + 1;
                q.emplace(mx, my);
            }
        }
    }
}

bool isout(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1; 
}

struct node { int x, y, t; };
vector<vii> p;
vector<vc> path;

bool bfs(int x, int y) {
    p = vector<vii> (n, vii(m));
    path = vector<vc> (n, vc(m));
    queue<node> q;
    q.push({x, y, 0});
    while(!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        int t = q.front().t;
        if(isout(x, y)) {
            fi = mp(x, y);
            return 1;
        }
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(check(mx, my) && !vis[mx][my] && t + 1 < times[mx][my]) {
                vis[mx][my] = 1;
                p[mx][my] = {x, y};
                path[mx][my] = dir[i];
                q.push({mx, my, t + 1});
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'M') mstr.emplace_back(i, j);
            if(a[i][j] == 'A') si = mp(i, j);
        }
    }
    floodfill(mstr);
    if(bfs(si.ft, si.sd)) {
        cout << "YES" << endl;
        string ans;
        int x = fi.ft, y = fi.sd;
        while(x != si.ft || y != si.sd) {
            ans += path[x][y];
            int tx = x, ty = y;
            x = p[tx][ty].ft, y = p[tx][ty].sd;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}