#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 55;
int n, m;
int h[2][MXN], a[2][MXN], d[2][MXN];
int match[MXN];
bool vis[MXN];
vector<int> g[MXN];

bool ok(int i, int j) {
    return abs(h[0][i] - h[1][j]) <= 12 && abs(a[0][i] - a[1][j]) <= 5 && d[0][i] == d[1][j];
}

bool bpm(int u) {
    for(int i = 0; i < m; i++) {
        if(ok(u, i)){ 
            if(vis[i]) continue;
            vis[i] = 1;
            if(match[i] == -1 || bpm(match[i])) {
                match[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> h[0][i] >> a[0][i] >> d[0][i];
    }
    for(int i= 0; i < m; i++) {
        cin >> h[1][i] >> a[1][i] >> d[1][i];        
    }
    int ans = 0;
    memset(match, -1, sizeof match);
    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        if(bpm(i)) ans++;
    }
    return ans;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": " << solve() << endl;
    }
    return 0;
}