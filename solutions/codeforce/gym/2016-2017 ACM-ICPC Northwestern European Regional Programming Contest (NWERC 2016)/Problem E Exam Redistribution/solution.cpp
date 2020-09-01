#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 35;
pair<int, int> a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s; cin >> s;
        a[i] = {s, i};
    }
    sort(a, a + n, greater<pair<int,int>>());
    queue<int> q;
    for(int i = 0; i < a[0].first; i++) q.push(a[0].second);
    for(int i = 1; i < n; i++) {
        int tmp = a[i].first;
        while(tmp) {
            q.push(a[i].second);
            tmp--;
            q.pop();
        }
    }
    bool ok = q.size() >= a[0].first;
    while(!q.empty()) {
        if(q.front() == a[0].second) ok = 0;
        q.pop();
    }
    if(ok) {
        for(int i = 0; i < n; i++) {
            cout << a[i].second  + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}