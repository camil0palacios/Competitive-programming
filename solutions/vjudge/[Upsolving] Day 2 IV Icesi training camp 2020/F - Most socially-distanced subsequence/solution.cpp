#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n - 1 || a[i - 1] < a[i] != a[i] < a[i + 1]) {
                ans.emplace_back(a[i]);
            }
        }
        cout << ans.size() << endl;
        for(auto & i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}