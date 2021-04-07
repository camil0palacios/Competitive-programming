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
ll a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll s1 = 0, s2 = 0, mx1 = 0, mx2 = 0, mn = 1e9;
    fori(i,0,n) {
        cin >> a[i];
        if(mx1 < a[i]) {
            mx2 = mx1;
            mx1 = a[i];
        }
        else if(mx2 < a[i]) mx2 = a[i];
        s1 += a[i];
    }
    fori(i,0,m) {
        cin >> b[i];
        s2 += b[i];
        mn = min(mn, b[i]);
    }
    if(mx1 > mn) { cout << -1 << endl; return 0; }
    ll ans = s1*m + s2;
    ans -= mx1*m;
    if(mx1 < mn) ans += mx1 - mx2;
    cout << ans << endl;
    return 0; 
}