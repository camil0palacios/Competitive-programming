#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 55;
int n, p1, p2, p3;
int dist[MXN][MXN][MXN];
char mat[MXN][MXN];

struct node {
    int a, b, c;
    node(){}
    node(int a, int b, int c): a(a), b(b), c(c) {}
};

void bfs() {
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            for(int k = 0; k < n; k++) 
                dist[i][j][k] = INF;
    queue<node> q;
    q.emplace(p1, p2, p3);
    dist[p1][p2][p3] = 0;
    while(!q.empty()) {
        int u = q.front().a;
        int v = q.front().b;
        int w = q.front().c;
        q.pop();
        if(u == v && v == w) {
            cout << dist[u][v][w] << endl;
            return;
        }
        int d = dist[u][v][w] + 1;
        for(int i = 0; i < n; i++) {
            if(mat[v][w] == mat[u][i] && d < dist[i][v][w]) {
                dist[i][v][w] = d;
                q.emplace(i, v, w);
            }
            if(mat[u][w] == mat[v][i] && d < dist[u][i][w]) {
                dist[u][i][w] = d;
                q.emplace(u, i, w); 
            }
            if(mat[u][v] == mat[w][i] && d < dist[u][v][i]) {
                dist[u][v][i] = d;
                q.emplace(u, v, i);
            }
        }
    }
    cout << "impossible" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n, n) {
        cin >> p1 >> p2 >> p3;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        p1--, p2--, p3--;
        bfs();
    }
    return 0;
}