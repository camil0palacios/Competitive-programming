#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
#define ft first
#define sd second
using namespace std;

typedef pair<int,pair<pair<int,int>,int>> node;

const int INF = 1e9;
int n, m, r, s;
int xi, yi, xf, yf;
char a[25][25];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(14);
    cin >> n >> m >> r >> s;
    xi = -1, yi = -1, xf = -1, yf = -1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j]; 
            if(a[i][j] != '.') {
                if(xf == -1) xf = i, yf = j;
                xi = i, yi = j; 
                sum += a[i][j] - '0';
            }
        }
    }
    double dist[n][m][sum + 1];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            for(int d = 0; d <= min(s, sum); d++)
                dist[i][j][d] = INF;
    priority_queue<node, vector<node>, greater<node>> q;
    dist[xi][yi][a[xi][yi] - '0'] = 0;
    q.emplace(0, mp(mp(xi, yi), a[xi][yi] - '0'));
    while(!q.empty()) {
        int i = q.top().sd.ft.ft;
        int j = q.top().sd.ft.sd;
        int st = q.top().sd.sd;
        int dis = q.top().ft;
        q.pop();
        if(dis > dist[i][j][st]) continue;
        for(int x = -r; x <= r; x++) {
            for(int y = -r; y <= r; y++) {
                int mx = i + x, my = j + y;
                if(mx == i && my == j) continue;
                if(mx >= 0 && mx < n && my >= 0 && my < m && a[mx][my] != '.' &&   
                    x*x + y*y <= r*r && st + (a[mx][my] - '0') <= min(s, sum) &&
                    dist[i][j][st] + sqrt(1.0*x*x + 1.0*y*y) < dist[mx][my][st + (a[mx][my] - '0')]
                ){
                        dist[mx][my][st + (a[mx][my] - '0')] = dist[i][j][st] + sqrt(1.0*x*x + 1.0*y*y);
                        int x = dist[mx][my][st + (a[mx][my] - '0')];
                        q.emplace(x, mp(mp(mx, my), st + (a[mx][my] - '0')));
                }
            }
        }
    }
    double ans = INF;
    for(int i = 0; i <= min(s, sum); i++) {
        ans = min(ans, dist[xf][yf][i]);
    }
    if(ans < INF) cout << ans << endl;
    else cout << "impossible" << endl;
    return 0;
}