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

const int mod = 1e9 + 7;
const int Mxn = 1e6 + 5;
ll l[Mxn], h[Mxn];
ll a[Mxn], b[Mxn];

void solve() {
    int n, k, w;
    cin >> n >> k >> w;
    fore(i,1,k) cin >> l[i];
    fori(i,0,4) cin >> a[i];
    fore(i,1,k) cin >> h[i];
    fori(i,0,4) cin >> b[i];
    fore(i,k+1,n) {
        l[i] = ((a[0]*l[i-2] + a[1]*l[i-1] + a[2]) % a[3]) + 1;
        h[i] = ((b[0]*h[i-2] + b[1]*h[i-1] + b[2]) % b[3]) + 1;
    }
    ll ans = 1, per = 0, pre = 0;
    ll left = 0, right = 0, ch = 0;
    map<int, ll> m;
    fore(i,1,n) {
        ll mx = 0;
        fore(j, l[i], l[i] + w) mx = max(mx, m[j]);
        if(right < l[i]){
            left = l[i];
            pre = per;
            ch = (2 * h[i]) % mod;
        } else {
            if(mx < h[i]) {
                ch = ((ch - mx + mod) % mod + (h[i] - mx + mod) % mod + h[i]) % mod;    
            }
        }
        right = l[i] + w;   
        per = (pre + 2*(right - left) + ch) % mod;
        ans = (ans * per) % mod;
        fore(j, l[i], l[i] + w) m[j] = max(m[j], h[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i <<  ": ";
        solve();
    }
    return 0; 
}