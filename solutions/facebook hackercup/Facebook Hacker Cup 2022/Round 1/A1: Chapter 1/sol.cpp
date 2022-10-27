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

const int N = 5e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    fori(i,0,n) cin >> a[i];
    fori(i,0,n) cin >> b[i];
    if(n == 2) {
        if(a == b) cout << (k % 2 == 0 ? "YES" : "NO") << endl;
        else {
            reverse(all(a));
            cout << ((a == b && (k & 1)) ? "YES" : "NO") << endl;
        }
        return;
    }
    if(k == 0) {
        cout << (a == b ? "YES" : "NO") << endl;
        return;
    }
    if(k == 1 && a == b) {
        cout << "NO" << endl;
        return;
    }
    int idx = 0;
    fori(i,0,n) if(a[0] == b[i]) {
        idx = i;
        break;
    }
    rotate(b.begin(), b.begin()+idx, b.end());
    cout << (a == b ? "YES" : "NO") << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}