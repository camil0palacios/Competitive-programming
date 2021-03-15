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
    sort(t.begin(), t.end());
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(!q.empty() && q.top() < t[i].first) q.pop();
        q.push(t[i].second);
        ans = max(ans, (int)q.size());
    }
    cout << ans << endl;
    return 0;
}