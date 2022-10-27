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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x, s;
        cin >> n >> x >> s;
        ll ans = 0, a = 0;
        int mpl = 1e9, mps = 1e9;
        fori(i,0,n) {
            int c, pl, ps;
            cin >> c >> pl >> ps;
            mpl = min(mpl, pl);
            mps = min(mps, ps);
            int pounds = (c*s - a + 79) / 80;
            ans += 1ll*c*mpl*x + 1ll*mps*pounds;
            a = ((80*pounds + a) - c*s);
        }
        cout << ans << endl;
    }
    
    return 0; 
}