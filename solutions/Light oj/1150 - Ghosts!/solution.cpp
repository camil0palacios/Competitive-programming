#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define ll long long
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> edge;

const int INF = 1e9;
const int MXN = 110;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char a[MXN][MXN];
bool vis[MXN], seen[MXN][MXN];
int match[MXN], dist[MXN][MXN];
vector<int> g[MXN];
vector<ii> ghost, human;
vector<edge> e;

bool bmp(int u) {
    for(auto & v : g[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        if(match[v] == -1 || bmp(match[v])) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int check(int lim) {
    int n = ghost.size() + human.size();
    for(int i = 0; i < n; i++) g[i].clear();
    for(int i = 0; i < e.size(); i++) {
        if(e[i].sd <= lim) {
            int u = e[i].ft.ft, v = e[i].ft.sd;
            g[u].emplace_back(v);
        }
    }
    memset(match, -1, sizeof match);
    int res = 0;
    for(int i = 0; i < ghost.size(); i++) {
        memset(vis, 0, sizeof vis);
        if(bmp(i)) res++;
    }
    return res;
}

void bfs(int x, int y, int n) {
    queue<ii> q;
    q.push(mp(x, y));
    seen[x][y] = dist[x][y] = 0;
    while(!q.empty()) {
        x = q.front().ft;
        y = q.front().sd;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if(mx >= 0 && mx < n && my >= 0 && my < n && !seen[mx][my] && a[mx][my] != '#') {
                seen[mx][my] = 1;
                dist[mx][my] = dist[x][y] + 1;
                q.push(mp(mx, my)); 
            }
        }
    }
}

void solve() {
    int n; 
    cin >> n;
    ghost.clear(), human.clear();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'G') ghost.emplace_back(i, j);
            if(a[i][j] == 'H') human.emplace_back(i, j);
        }
    }
    e.clear();
    for(int i = 0; i < ghost.size(); i++) {
        memset(dist, -1, sizeof dist);
        memset(seen, 0, sizeof seen);
        bfs(ghost[i].ft, ghost[i].sd, n);
        for(int j = 0; j < human.size(); j++) {
            int x = human[j].ft, y = human[j].sd;
            if(dist[x][y] != -1)
                e.emplace_back(mp(i, j + ghost.size()), dist[x][y]);
        }
    }
    if(check(INF) < human.size()) {
        cout << "Vuter Dol Kupokat" << endl;
    } else {
        int l = 0, r = n * n + 1, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid) == human.size()) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans*2 + 2 << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}