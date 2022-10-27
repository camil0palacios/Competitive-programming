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

const int Mxn = 110;
char a[Mxn][Mxn];
char b[Mxn][Mxn];

void solve() {
    int n, m;
    cin >> n >> m;
    fori(i,0,n) fori(j,0,m) cin >> a[i][j], b[i][j] = '0';
    vector<ar<int, 4>> ans;
    fori(i,0,n) { 
        fori(j,0,m) {
            if(a[i][j] == '1' && j) {
                int p = j;
                while(p < m && a[i][p] == '1') p++;
                int tmp = p;
                p--;
                while(p >= j) {
                    ans.push_back({i, p-1, i, p});
                    b[i][p-1] = '0', b[i][p] = '1';
                    p--;
                }
                j = tmp-1;
            }
        }
    }
    fori(i,1,n) {
        if(a[i][0] == '1') {
            int p = i;
            while(p < n && a[p][0] == '1') p++;
            int tmp = p;
            p--;
            while(p >= i) {
                ans.push_back({p-1, 0, p, 0});
                b[p-1][0] = '0', b[p][0] = '1';
                p--;
            }
            i = tmp-1;
        }
    }
    bool ok = 1;
    fori(i,0,n) {
        fori(j,0,m) ok &= a[i][j] == b[i][j];
    }
    if(ok) {
        cout << sz(ans) << endl;
        for(auto & v : ans) {
            fori(i,0,4) cout << v[i]+1 << ' ';
            cout << endl;
        }
    }
    else cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}