#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int s = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        cout << min(s, m) << endl;
    }
    return 0;
}