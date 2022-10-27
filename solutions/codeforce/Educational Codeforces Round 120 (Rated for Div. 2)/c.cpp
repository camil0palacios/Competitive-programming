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

const ll oo = 1e18;
const int N = 2e5 + 5;
int a[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll k;
        cin >> n >> k;
        ll s = 0;
        fori(i,0,n) cin >> a[i], s += a[i];
        if(s <= k) {
            cout << 0 << endl;
            continue;
        }
        sort(a, a+n);
        ll ans = oo;
        a[n] = a[0];
        forr(i,n,1) {
            s -= a[i];
            ll l = 0, r = 1e9, tp = -1; 
            while(l <= r) {
                ll m = (l + r) >> 1;
                ll mn = a[0] - m;
                if(mn*(n-i+1) + s <= k) tp = m, r = m-1;
                else l = m+1; 
            }
            if(tp != -1) ans = min(ans, n-i+1 + tp);
        }
        cout << ans-1 << endl;
    }
    return 0; 
}