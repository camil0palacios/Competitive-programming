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

const int mod = 1e9 + 7;
const int Mxn = 2e5 + 5;
int a[Mxn];

void solve() {
    int n;
    cin >> n;
    map<int,int> m;
    fori(i,0,n) cin >> a[i], m[a[i]]++;
    int an = a[0];
    fori(i,1,n) an &= a[i];
    if(m[an] >= 2) {
        ll ans = 1ll*m[an]*(m[an]-1);
        fore(i,1,n-2) ans = (ans * i) % mod;
        cout << ans << endl;
    } else cout << 0 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}