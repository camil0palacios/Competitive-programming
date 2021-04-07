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

const int Mxn = 40040;
bool s[Mxn];
vi p, com, d;
vii f[2];

void cal() {
    memset(s, 0, sizeof s);
    p.eb(2);
    for(ll i = 3; i < Mxn; i += 2) {
        if(!s[i]) {
            p.eb(i);
            for(ll j = i*i; j < Mxn; j += i)
                s[j] = 1;
        }
    }
}

void fact(int x, int y) {
    for(int i = 0; i < sz(p) && 1ll*p[i]*p[i] <= x; i++) {
        if(x % p[i] == 0) {
            int cnt = 0;
            while(x % p[i] == 0) { cnt++; x /= p[i]; }
            f[y].eb(p[i], cnt);
        }
    }
    if(x > 1) f[y].eb(x, 1);
}

void getDivisors(int i, int val) {
    if(i == sz(com)) {
        d.eb(val);
        return;
    }
    getDivisors(i+1, val);
    getDivisors(i+1, val*com[i]);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int n, a, b;
    cin >> a >> b >> n;
    fact(a, 0);
    fact(b, 1);
    int j = 0;
    fori(i,0,sz(f[0])) {
        while(j < sz(f[1]) && f[1][j].ft < f[0][i].ft) j++;
        if(f[0][i].ft == f[1][j].ft) {
            int mn = min(f[0][i].sd, f[1][j].sd);
            fori(x,0,mn) com.eb(f[0][i].ft);
        }
        // int j = lower_bound(all(f[1]), mp(f[0][i].ft, 0)) - f[1].begin();
        // if(j < sz(f[1]) && f[0][i].ft == f[1][j].ft) {
        //     int mn = min(f[0][i].sd, f[1][j].sd);
        //     fori(j,0,mn) com.eb(f[0][i].ft);
        // }
    }
    getDivisors(0, 1);
    sort(all(d));
    d.erase(unique(all(d)), d.end());
    fori(i,0,n) {
        int lo, hi;
        cin >> lo >> hi;
        int ans = -1;
        int l = 0, r = sz(d)-1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(d[mid] < lo) l = mid+1;
            else if(hi < d[mid]) r = mid-1;
            else {
                ans = d[mid];
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}