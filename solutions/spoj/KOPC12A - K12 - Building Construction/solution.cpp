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
int n;
int h[Mxn];
int c[Mxn];

ll f(int x) {
    ll ans = 0;
    fori(i,0,n)
        ans += 1ll*abs(x - h[i])*c[i];
    return ans;
}

void solve() {
    cin >> n;
    fori(i,0,n) cin >> h[i];
    fori(i,0,n) cin >> c[i];
    int l = 0, r = 10005;
    fori(i,0,100) {
        int m1 = l + (r - l) / 3; 
        int m2 = r - (r - l) / 3;
        if(f(m1) <= f(m2)) r = m2;
        else l = m1;
    }
    ll ans = f((l+r)/2);
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}