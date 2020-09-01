#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1010;
char g[2*MXN + 5][2*MXN + 5];
int p[4*MXN*MXN + 5];

int find(int a) {
    return a == p[a] ? a : p[a] = find(p[a]);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) p[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    memset(g, '.', sizeof g);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '.') continue;
            if(s[j] == '/') {
                g[2*i + 1][2*j + 2] = '#';
                g[2*i + 2][2*j + 1] = '#';
            } else {
                g[2*i + 1][2*j + 1] = '#';
                g[2*i + 2][2*j + 2] = '#';
            }
        }
    }
    int mxn = 2*n + 2;
    int mxm = 2*m + 2;
    for(int i = 0; i < mxn; i++) {
        for(int j = 0; j < mxm; j++) {
            if(g[i][j] == '#') continue;
            p[i*mxm + j] = i*mxm + j;
            if(i > 0 && g[i - 1][j] == '.') join((i - 1)*mxm + j, i * mxm + j);
            if(j > 0 && g[i][j - 1] == '.') join(i*mxm + j - 1, i * mxm + j);
        }
    }   
    int ans = 0;
    for(int i = 0; i < mxn; i++) {
        for(int j = 0; j < mxm; j++) {
            if(p[i*mxm + j] == i * mxm + j) 
                ans++;
        }
    } 
    cout << ans - 1 << endl;
    return 0;
}