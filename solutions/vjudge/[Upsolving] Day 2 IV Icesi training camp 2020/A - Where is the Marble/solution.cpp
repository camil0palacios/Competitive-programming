#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int s[MXN], in[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, cs = 0;
    while(cin >> n >> q && (n || q)) {
        memset(s, 0, sizeof s);
        memset(in, 0, sizeof in);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            in[x] = 1, s[x]++;
            mx = max(mx, x);
        }
        for(int i = 1; i <= mx; i++) {
            s[i] += s[i - 1];
        } 
        cout << "CASE# " << ++cs << ":" << endl;
        for(int i = 0; i < q; i++) {
            int x; cin >> x;
            if(in[x]) cout << x << " found at " << s[x - 1] + 1 << endl;
            else cout << x << " not found" << endl;
        }
    }
    return 0;
}