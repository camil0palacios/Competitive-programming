#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n == 3 || n == 2) cout << "NO SOLUTION" << endl;
    else {
        vector<bool> vis(n + 1, 0);
        vector<int> ans;
        int j = n;
        for(int i = 1; i <= n; i++) {
            j = n - i + 1;
            if(vis[i]) continue;
            if(j - i + 1 > 5) {
                ans.emplace_back(i);
                ans.emplace_back(j);
                vis[i] = vis[j] = 1;
            } else break;
        }
        for(int i = j - 2; i >= 1; i--) {
            if(vis[i]) continue;
            vis[i] = 1;
            ans.emplace_back(i);
            if(i + 2 <= n && !vis[i + 2]) {
                vis[i + 2] = 1;
                ans.emplace_back(i + 2);
            }
        }
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0; 
}