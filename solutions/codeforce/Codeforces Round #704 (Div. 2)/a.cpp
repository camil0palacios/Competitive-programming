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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll x = (p + a - 1)/a;
        ll y = (p + b - 1)/b;
        ll z = (p + c - 1)/c;
        ll v[3] = {x*a, y*b, z*c};
        ll ans = 2e18;
        fori(i,0,3) ans = min(ans, v[i] - p); 
        cout << ans << endl;
    }
    return 0; 
}