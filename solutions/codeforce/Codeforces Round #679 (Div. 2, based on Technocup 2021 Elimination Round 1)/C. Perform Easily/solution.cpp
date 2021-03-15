#include <bits/stdc++.h>
#define endl '\n'
#define fori(i, a, b) for(int i = a; i < b; i++) 
#define forr(i, a, b) for(int i = a; i >= b; i--)
#define all(v) v.begin(),v.end()
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
const int MXN = 1e5 + 5;
const int INF = 2e9;
int n;
int a[6], b[MXN];
int vis[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i, 0, 6) cin >> a[i];
    cin >> n;
    vector<ii> p;
    fori(i, 0, n) {
        cin >> b[i];
        fori(j, 0, 6) {
            p.emplace_back(b[i] - a[j], i);
        }
    }
    sort(all(p));
    int l = 0, r = 0, sz = 0;
    int ans = INF;
    while(r < p.size()) {
        while(r < p.size() && sz < n) {
            sz += !vis[p[r++].sd]++;
        }
        while(l < r && sz == n) {
            sz -= vis[p[l++].sd]-- == 1;
        }
        ans = min(ans, p[r - 1].ft - p[l - 1].ft);
    }
    cout << ans << endl;
    return 0;
}