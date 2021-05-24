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

const int Mxn = 1e5 + 5;
int n, m;
ll a[Mxn], b[Mxn];

ll check(ll x) {
    ll ans = 0;
    fori(i,0,n) if(a[i] < x) ans += x - a[i];
    fori(i,0,m) if(b[i] > x) ans += b[i] - x;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    fori(i,0,n) cin >> a[i];
    fori(i,0,m) cin >> b[i];
    ll ans = 1e18;
    ll l = 1, r = 1e9;
    fori(i,0,100) {
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r-l)/3;
        ll f = check(m1), g = check(m2);
        ans = min(ans, min(f, g));
        if(f <= g) r = m2;
        else l = m1;
    }
    ans = min(ans, check((l+r)/2));
    cout << ans << endl;
    return 0; 
}