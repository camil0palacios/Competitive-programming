#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end(), [&](const ii & a, const ii & b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int ans = 0, curt = 0;
    for(int i = 0; i < n; i++) {
        if(curt <= t[i].first) {
            curt = t[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}