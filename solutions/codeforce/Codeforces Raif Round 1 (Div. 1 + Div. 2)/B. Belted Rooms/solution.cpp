#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> vis(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '-') {
                vis[i] = 1, 
                vis[(i + 1) % n] = 1;
            }
        }
        int ans = accumulate(vis.begin(), vis.end(), 0);
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '>') a++;
            if(s[i] == '<') b++;
        } 
        if(min(a, b) == 0) ans = n;
        cout << ans << endl;
    }
    return 0;
}