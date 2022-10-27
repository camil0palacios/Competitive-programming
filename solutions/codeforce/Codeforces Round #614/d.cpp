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

ll lim = 1e18;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll x0, y0, ax, bx, ay, by;
    ll xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    vl x, y;
    x.eb(x0), y.eb(y0);
    fore(i,1,100) {
        if(x0 <= (lim-bx)/ax && y0 <= (lim-by)/ay) {
            x0 = ax * x0 + bx;
            y0 = ay * y0 + by;
            x.eb(x0), y.eb(y0);
        }
    }
    int n = sz(x);
    int ans = 0;
    fori(i,0,n) {
        fori(j,0,n) {
            ll d1 = abs(x[i]-xs) + abs(y[i]-ys);
            ll d2 = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            if(d1 + d2 <= t) ans = max(ans, abs(j - i) + 1);
        }
    }
    cout << ans << endl;
    return 0; 
}