#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e6 + 5;
int l[MXN], p[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for(int i = 0; i < n; i++) {
        if(l[i] != 0) {
            int j = max(0, i - l[i]);
            p[j]--, p[i]++;
        }
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += p[i];
        p[i] = s;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += p[i] >= 0;
    }
    cout << ans << endl;
    return 0;
}