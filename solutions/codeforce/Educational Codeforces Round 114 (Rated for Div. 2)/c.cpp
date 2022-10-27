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
ll a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    sort(a, a+n);
    ll s = 0;
    fori(i,0,n) s += a[i];
    cin >> m;
    fori(q,0,m) {
        ll x, y;
        cin >> x >> y;
        int j = lower_bound(a, a+n, x) - a;
        ll ans = 2e18;
        if(j == n) j = n-1;
        fori(i,max(0, j-100),min(n, j+100)) {
            ans = min(ans, max(0ll, x - a[i]) + max(0ll, y - (s - a[i])));
        }
        cout << ans << endl;
    } 
    return 0; 
}