#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int INF = 1e9;
const int MXN = 55;
vector<pair<int,int>> p[MXN*MXN];
int dp[MXN*MXN][MXN*MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            p[x].emplace_back(i, j);
        }
    }
    for(int i = 1; i <= k; i++) for(int j = 0; j < p[i].size(); j++) dp[i][j] = INF;
    for(int i = 0; i < p[k].size(); i++) dp[k][i] = 0;
    for(int i = k - 1; i >= 1; i--) {
        for(int j = 0; j < p[i].size(); j++) {
            int x1 = p[i][j].first, y1 = p[i][j].second;
            for(int x = 0; x < p[i + 1].size(); x++) {
                int x2 = p[i + 1][x].first, y2 = p[i + 1][x].second;
                dp[i][j] = min(dp[i][j], dp[i + 1][x] + abs(x1 - x2) + abs(y1 - y2));
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < p[1].size(); i++) {
        ans = min(ans, dp[1][i]);
    }
    cout << (ans < INF ? ans : -1) << endl;
    return 0;
}