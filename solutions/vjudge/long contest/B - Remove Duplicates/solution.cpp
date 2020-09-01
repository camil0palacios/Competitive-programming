#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> v;
    bool vis[1010];
    memset(vis, 0, sizeof vis);
    for(int i = n - 1; i >= 0; i--) {
        if(!vis[a[i]]) {
            vis[a[i]] = 1;
            v.push_front(a[i]);
        }
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}