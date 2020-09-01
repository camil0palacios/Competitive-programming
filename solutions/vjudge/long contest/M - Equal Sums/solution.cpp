#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int sum[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    vector<int> a[k];
    for(int i = 0; i < k; i++) {
        int n; cin >> n;
        a[i].resize(n);
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }
    vector< tuple<int, int, int> > t;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            t.emplace_back(sum[i] - a[i][j], i, j);
        }
    }
    sort(t.begin(), t.end());
    bool ok = 0;
    int f = 0, s = 0, x = 0, y = 0;
    for(int i = 1; i < t.size(); i++) {
        if(get<0>(t[i]) == get<0>(t[i - 1]) && get<1>(t[i]) != get<1>(t[i - 1])) {
            f = get<1>(t[i - 1]), s = get<1>(t[i]);
            x = get<2>(t[i - 1]), y = get<2>(t[i]);
            ok = 1;
            break;
        }
    }
    if(ok) {
        cout << "YES" << endl;
        cout << f + 1 << ' ' << x + 1 << endl;
        cout << s + 1 << ' ' << y + 1 << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}