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

const int mod = 1e9 + 7;
const int MaxA = 3010;

ll sq2(ll x) { return (x*x) % mod; }

void get_sum(vl & x, vl & ans) {
    int n = sz(x);
    fori(i,0,n) {
        fori(j,0,n) {
            ans[i] = (ans[i] + (sq2(i - j) * x[j]) % mod) % mod;
        }
    }
}

void solve() {
    int n, q;
    cin >> n;
    vl x(MaxA), y(MaxA);
    vl ansX(MaxA), ansY(MaxA);
    fori(i,0,n) {
        int a, b;
        cin >> a >> b;
        x[a]++, y[b]++;
    }
    get_sum(x, ansX);
    get_sum(y, ansY);
    cin >> q;
    ll ans = 0;
    fori(i,0,q) {
        int xi, yi;
        cin >> xi >> yi;
        ans = ((ans + ansX[xi]) % mod + ansY[yi]) % mod;
    }
    cout << ans << endl;
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