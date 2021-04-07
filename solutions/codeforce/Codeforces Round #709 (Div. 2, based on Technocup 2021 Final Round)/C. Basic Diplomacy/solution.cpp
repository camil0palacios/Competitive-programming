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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
vi a[Mxn];
int f[Mxn], acc[Mxn];

void solve() {
    int n, m;
    cin >> n >> m;
    fore(i,0,n) f[i] = acc[i] = 0;
    fori(i,0,m) {
        int x; cin >> x;
        a[i].clear();
        fori(j,0,x) {
            int y; cin >> y;
            a[i].eb(y);
        }
        if(x == 1) f[a[i][0]]++;
    }
    vi ans;
    fori(i,0,m) {
        int p = -1, mn = 1e9;
        fori(j,0,sz(a[i])) {
            int x = acc[a[i][j]] + f[a[i][j]] + (sz(a[i]) == 1 ? -1 : 0) + 1;
            if(x <= (m + 1)/2 && x < mn) {
                p = j, mn = x;
            }
        }
        if(p == -1) { cout << "NO" << endl; return; }
        acc[a[i][p]]++;
        if(sz(a[i]) == 1) f[a[i][p]]--;
        ans.eb(a[i][p]);
    }
    cout << "YES" << endl;
    for(auto & i : ans) cout << i << ' ';
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}