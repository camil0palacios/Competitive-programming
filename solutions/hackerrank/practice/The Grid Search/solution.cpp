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

const int Mxn = 1100;
string a[Mxn], b[Mxn];

void solve() {
    int R, C, r, c;
    cin >> R >> C;
    fori(i,0,R) cin >> a[i];
    cin >> r >> c;
    fori(i,0,r) cin >> b[i];
    fori(i,0,R-r+1) {
        fori(j,0,C-c+1) {
            if(a[i][j] == b[0][0]) {
                bool ok = 1;
                fori(k,0,r) {
                    if(a[i+k].substr(j, c) != b[k]) { ok = 0; break; }
                }
                if(ok) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}