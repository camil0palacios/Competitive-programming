#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;
int a[MXN][MXN], b[MXN], c[MXN];
int ans1[MXN], ans2[MXN];

void sol() {
    int n, m, h, v;
    cin >> n >> m >> h >> v;
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char cc; cin >> cc;
            a[i][j] = cc == '@';
            if(a[i][j]) {
                b[i + 1]++;
                c[j + 1]++;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    for(int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    h++;
    v++;
    bool ok = 1;
    for(int i = 0; i <= h; i++) {
        ans1[i] = -1;
        for(int j = 0; j <= n; j++)
            if(b[j] * h == b[n] * i) 
                ans1[i] = j;
        if(ans1[i] == -1) ok = 0;
    }
    for(int i = 0; i <= v; i++) {
        ans2[i] = -1;
        for(int j = 0; j <= m; j++)
            if(c[j] * v == c[m] * i)
                ans2[i] = j;
        if(ans2[i] == -1) ok = 0;
    }
    int s = b[n] / (h * v);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < v; j++) {
            int cnt = 0;
            for(int x = ans1[i]; x < ans1[i + 1]; x++) {
                for(int y = ans2[j]; y < ans2[j + 1]; y++) {
                    cnt += a[x][y];
                }
            }
            if(cnt != s) ok = 0;
        }
    }
    cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol(); 
    }
    return 0;
}