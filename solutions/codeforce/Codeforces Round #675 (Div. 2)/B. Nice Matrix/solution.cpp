#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int INF = 1e9;
const int MXN = 101;
int a[MXN][MXN];
int n, m;

ll get(vector<int>& v) {
    ll ans = 1e18;
    for(auto & x: v) {
        ll tmp = 0;
        for(auto y: v) {
            tmp += abs(y - x);
        }
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        for(int i = 0; i < (n + 1) / 2; i++) {
            for(int j = 0; j < (m + 1) / 2; j++) {
                vector<int> v;
                v.emplace_back(a[i][j]);
                if(i != n - i - 1) v.emplace_back(a[n - i - 1][j]);
                if(j != m - j - 1) v.emplace_back(a[i][m - j - 1]);
                if(i != n - i - 1 && j != m - j - 1) v.emplace_back(a[n - i - 1][m - j - 1]);
                ans += get(v); 
            }
        }
        cout << ans << endl;
    }
    return 0;
}