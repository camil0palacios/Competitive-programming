#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 120 * 80 + 5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> g(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> g[i];
        }
        int x, y;
        cin >> x >> y;
        vector<vector<int>> dist(121, vector<int> (81, INF));
        queue<pair<int,int>> q;
        q.emplace(x, y);
        dist[x][y] = 0;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if(x == mx) {
                    if(my < 0 && mx - 1 >= 1) {
                        mx = mx - 1, my = g[mx];
                    } 
                    else if (my > g[mx] && mx + 1 <= n) { 
                        mx = mx + 1, my = 0;
                    }
                } 
                else if(my > g[mx]) {
                    my = g[mx];
                }
                if(mx >= 1 && mx <= n && my >= 0 && my <= g[mx] && dist[x][y] + 1 < dist[mx][my]) {
                    dist[mx][my] = dist[x][y] + 1;
                    q.emplace(mx, my);
                }
            }
        }
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
    return 0;
}