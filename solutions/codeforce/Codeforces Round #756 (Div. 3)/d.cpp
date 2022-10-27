#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
int b[Mxn], p[Mxn];
int d[Mxn], w[Mxn], vis[Mxn];

void solve() {
    int n;
    cin >> n;
    fore(i,1,n) d[i] = w[i] = -1;
    fore(i,1,n) cin >> b[i];
    fore(i,1,n) cin >> p[i];
    fore(i,1,n) {
        int x = p[i], pr = b[x];
        if(x == pr) {
            d[x] = w[x] = 0;
            continue;
        }
        if(d[pr] == -1 || d[p[i-1]] < d[pr]) {
            cout << -1 << endl;
            return;
        }
        w[x] = d[p[i-1]] - d[pr] + 1;
        d[x] = d[pr] + w[x];
    }
    bool ok = 1;
    fore(i,2,n) ok &= d[p[i-1]] < d[p[i]];
    if(ok) {
        fore(i,1,n) cout << w[i] << ' ';
        cout << endl;
    } else cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}