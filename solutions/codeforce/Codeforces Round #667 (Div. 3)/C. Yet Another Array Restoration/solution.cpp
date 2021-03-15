#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int ans = 1e9;
        int from = 0, sep = 0;
        for(int d = 1; d <= 50; d++) {
            for(int i = 1; i <= 50; i++) {
                int cur = i;
                vector<bool> vis(2501);
                for(int j = 0; j < n; j++) {
                    vis[cur] = 1;
                    cur += d;
                }
                cur -= d;
                if(vis[x] && vis[y] && cur < ans) {
                    ans = cur, from = i, sep = d;
                } 
            }
        }
        for(int i = 0; i < n; i++) {
            cout << from << ' ';
            from += sep;
        }
        cout << endl;
    }
    return 0;
}