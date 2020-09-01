#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            a[i].assign(k, 0);
            for(int j = 0; j < k; j++) {
                cin >> a[i][j];
                a[i][j]--;
            }
        }
        vector<int> vis(n), mar(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                if(!vis[a[i][j]]){
                    vis[a[i][j]] = 1;
                    mar[i] = a[i][j];
                    break;
                }
            }
        }
        bool ok = 1;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            if(mar[i] == -1) {
                ok = 0;
                x = i;
                for(int j = 0; j < n; j++) {
                    if(!vis[j]){
                        y = j;
                        break;
                    }
                }
                break;
            }
        }
        if(ok) cout << "OPTIMAL" << endl;
        else cout << "IMPROVE" << endl << x + 1 << ' ' << y + 1 << endl;
    }
    return 0;
}