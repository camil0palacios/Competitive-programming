#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;

int a[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[k] == 0) continue;
                x.emplace_back((a[i] + a[j]) * a[k]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                y.emplace_back(a[i] * a[j] + a[k]);
            }
        }
    }
    sort(all(y));
    sort(all(x));
    long long ans = 0;
    for(int i = 0; i < y.size(); i++) {
        int l = lower_bound(all(x), y[i]) - x.begin();
        int r = upper_bound(all(x), y[i]) - x.begin();
        ans += r - l;
    }
    cout << ans << endl;
    return 0;
}