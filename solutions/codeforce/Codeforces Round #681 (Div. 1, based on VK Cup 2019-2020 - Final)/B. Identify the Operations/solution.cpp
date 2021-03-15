#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 998244353;
const int MXN = 2e5 + 5;
int a[MXN], pos[MXN];
int b[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        set<int> s;
        for(int i = 0; i < k; i++) {
            cin >> b[i];
            s.insert(b[i]);
        } 
        int ans = 1;
        for(int i = 0; i < k; i++) {
            int p = pos[b[i]];
            if(p == 0) { if(s.count(a[p + 1])) { ans = 0; break; } }
            else if(p == n-1) { if(s.count(a[p - 1])) { ans = 0; break; } }
            else {
                int x = s.count(a[p - 1]), y = s.count(a[p + 1]);
                if(!x && !y) ans = (ans * 2) % mod;
                else if(x && y) { ans = 0; break; } 
            }
            s.erase(b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}