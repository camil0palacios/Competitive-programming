#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int neg = 0, s = 0, mn = 10010;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                if(x < 0) neg++;
                mn = min(mn, abs(x));
                s += abs(x); 
            }
        }
        if(neg & 1) s -= 2*mn;
        cout << s << endl;  
    }
    return 0;
}