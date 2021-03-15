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

const int Mxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, q;
bool sieve[Mxn];
int g[Mxn];
ll gcd = 1;
vi p;
map<int,int> a[Mxn];
multiset<ii> mn[Mxn];

ll be(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = (ans*x) % mod;
        x = (x*x) % mod;
        y >>= 1;
    }
    return ans;
}

void fact(int idx, int x) {
    for(int i = 0; i < sz(p) && 1ll*p[i]*p[i] <= 1ll*x; i++) {
        if(x % p[i] == 0) {
            int cnt = 0;
            while(x % p[i] == 0) cnt++, x /= p[i];
            int lst = a[idx][p[i]];
            a[idx][p[i]] += cnt;
            mn[p[i]].erase({lst, idx});
            mn[p[i]].insert({a[idx][p[i]], idx});
            auto pr = *mn[p[i]].begin();
            int to = pr.ft;
            if(sz(mn[p[i]]) == n && g[p[i]] < to) {
                gcd = (gcd * be(p[i], to - g[p[i]])) % mod;
                g[p[i]] = to;
            }
        }
    }
    if(x > 1) {
        int lst = a[idx][x];
        a[idx][x]++;
        mn[x].erase({lst, idx});
        mn[x].insert({a[idx][x], idx});
        auto pr = *mn[x].begin();
        int to = pr.ft;
        if(sz(mn[x]) == n && g[x] < to) {
            gcd = (gcd * be(x, to - g[x])) % mod;
            g[x] = to;
        }
    }
}

void cal() {
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    p.eb(2);
    for(ll i = 3; i < Mxn; i += 2) {
        if(sieve[i]) {
            p.eb(i);
            for(ll j = i*i; j < Mxn; j += i)
                sieve[j] = 0;
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    cin >> n >> q;
    fori(i,0,n) {
        int x; cin >> x;
        fact(i, x);
    }
    fori(i,0,q) {
        int idx, x; 
        cin >> idx >> x;
        fact(idx-1, x);
        cout << gcd << endl;
    }
    return 0; 
}