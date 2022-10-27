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

const ll oo = 1e12;
const int Mxn = 110;
int n;
int k[Mxn], h[Mxn];

ll gauss(ll x) {
    return x*(x+1)/2;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) cin >> k[i];
        fori(i,0,n) cin >> h[i];
        vii p;
        fori(i,0,n) p.eb(k[i]-h[i]+1, k[i]);
        sort(all(p));
        ll ans = 0;
        int l = 0, r = 0;
        fori(i,0,n) {
            if(p[r].sd < p[i].ft) {
                ans += gauss(p[r].sd - p[l].ft + 1);
                l = r = i;
            } else {
                if(p[r].sd < p[i].sd) r = i;
            }
        }
        ans += gauss(p[r].sd - p[l].ft + 1);
        cout << ans << endl;
    }
    return 0; 
}