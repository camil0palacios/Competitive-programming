#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i && a[i] == 1)ans.emplace_back(a[i - 1]);
    }
    ans.emplace_back(a[n - 1]);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}