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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const ll oo = 1e18;
const int Mxn = 2e5 + 5;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) cin >> b[i];
        vll c(1), d(1);
        fori(i,0,n) {
            if(b[i] == 1) c.eb(a[i]);
            else d.eb(a[i]);
        }
        sort(c.begin()+1, c.end(), greater<int>());
        sort(d.begin()+1, d.end(), greater<int>());
        fori(i,1,sz(c)) c[i] += c[i-1];
        fori(i,1,sz(d)) d[i] += d[i-1];
        ll ans = oo;
        fori(i,0,sz(c)) {
            int j = lower_bound(all(d), m - c[i]) - d.begin();
            if(j != sz(d)) {
                ans = min(ans, 1ll*i + 2*j);        
            } 
        }
        if(ans == oo) ans = -1;
        cout << ans << endl;
    }
    return 0; 
}