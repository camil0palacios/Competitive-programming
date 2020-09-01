#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a[m];
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        l--, r--;
        for(int j = l; j <= r; j++) {
            a[j]++;
        }
    }
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        if(a[i] == 0) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    if(ans.size()) cout << endl;
    return 0;
}