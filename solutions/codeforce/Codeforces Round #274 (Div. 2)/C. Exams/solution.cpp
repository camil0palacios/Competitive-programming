#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> events;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.emplace_back(a, b);
    }
    sort(events.begin(), events.end());
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(ans <= events[i].second) {
            ans = events[i].second;
        } else {
            ans = events[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}