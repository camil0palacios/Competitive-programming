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

const int Mxn = 2e5 + 5;
int a[Mxn], ord[Mxn];
int r[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i], ord[i] = i;
        sort(ord+1, ord+n+1, [&](int i, int j) { return a[i] > a[j]; });
        ll ans = 0;
        fore(i,1,n) {
            ll x = i & 1 ? i/2 + 1 : -i/2;
            ans += 2ll*abs(x)*a[ord[i]];
            r[ord[i]] = x;
        }
        cout << ans << endl;
        cout << 0 << ' ';
        fore(i,1,n) cout << r[i] << ' ';
        cout << endl;
    }
    return 0; 
}