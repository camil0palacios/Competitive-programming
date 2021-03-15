#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1005;
int a[MXN];

int main() {    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool ok = 0;
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(s.count(a[i])) ok = 1;
            s.insert(a[i]);
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}