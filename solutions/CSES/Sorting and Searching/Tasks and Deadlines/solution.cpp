#include <bits/stdc++.h>
#define endl '\n'
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;

typedef pair<int,int> ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ft >> a[i].sd;
    }
    sort(all(a));
    ll t = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        t += a[i].ft;
        ans += a[i].sd - t;
    }
    cout << ans << endl;
    return 0;
}