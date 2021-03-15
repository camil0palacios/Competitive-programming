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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(m);
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) cin >> b[i];
    fori(i,0,m) cin >> c[i];
    vi s[n+1];
    int tot = 0;
    set<int> any;
    fori(i,0,n) {
        if(a[i] != b[i]) {
            s[b[i]].eb(i);
            any.insert(i);
            tot++;
        }
    }
    if(count(all(b), c.back()) == 0) {
        cout << "NO" << endl;
        return;
    }
    vi ans(m);
    int pos = find(all(b), c.back()) - b.begin();
    fori(i,0,m) {
        if(tot == 0) {
            ans[i] = pos;
            continue;
        }
        if(sz(s[c[i]])) {
            ans[i] = s[c[i]].back();
            any.erase(ans[i]);
            s[c[i]].pop_back();
            tot--;
        } else {
            ans[i] = *any.begin();
        }
    }
    if(tot) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    fori(i,0,m) cout << ans[i]+1 << ' ';
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}