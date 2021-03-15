#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll oo = 1ll<<50;
const int Mxn = 1e5 + 5;
ll t[Mxn], x[Mxn];

bool inside(int l, int r, int x) {
    return min(l, r) <= x && x <= max(l, r);
}

int dir(int x) {
    return x < 0 ? -1 : x > 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> t[i] >> x[i];
        t[n] = oo;
        ll ans = 0, tl = 0, d = 0, xc = 0;
        fori(i,0,n) {
            if(tl == 0) {
                tl = abs(x[i] - xc);
                d = dir(x[i] - xc);
            }
            ll tm = min(tl, t[i+1]-t[i]);
            if(inside(xc, xc + d*tm, x[i])) ans++;
            xc += d*tm;
            tl -= tm;
        }
        cout << ans << endl;
    }
    return 0; 
}