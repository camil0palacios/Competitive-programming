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

const int mod = 998244353;
const int N = 2e5 + 5;
int x[N], y[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        fori(i,0,q) cin >> x[i] >> y[i];
        ll ans = 1;
        set<int> r, c;
        forr(i,q-1,0) {
            int ok = 0;
            if(!r.count(x[i])) r.insert(x[i]), ok = 1;
            if(!c.count(y[i])) c.insert(y[i]), ok = 1;
            if(ok) {
                ans = (1ll*ans*k) % mod;
            }
            if(sz(r) == n || sz(c) == m) break;
        }
        cout << ans << endl;
    }
    return 0; 
}