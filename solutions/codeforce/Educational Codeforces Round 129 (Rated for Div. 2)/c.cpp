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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 110;
int a[2][N], b[2][N];

void solve() {
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[0][i], a[1][i] = a[0][i];
    fori(i,0,n) cin >> b[0][i], b[1][i] = b[0][i];
    sort(a[1], a[1]+n);
    sort(b[1], b[1]+n);
    vii ans;
    fori(i,0,n) {
        if(a[0][i] != a[1][i] || b[0][i] != b[1][i]) {
            bool ok = 0;
            fori(j,i,n) {
                if(a[0][j] == a[1][i] && b[0][j] == b[1][i]) {
                    swap(a[0][i], a[0][j]);
                    swap(b[0][i], b[0][j]);
                    ans.eb(i, j);
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << sz(ans) << endl;
    for(auto [i, j] : ans) {
        cout << i+1 << ' ' << j+1 << endl;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}