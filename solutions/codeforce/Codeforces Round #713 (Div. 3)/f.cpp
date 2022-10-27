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
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n-1) cin >> b[i];
        ll ans = 1e16, d = 0, m = 0;
        fori(i,0,n) {
            ans = min(ans, d + max(0ll, (c-m+a[i]-1)/a[i]));
            ll d1 = ((b[i]-m+a[i]-1)/a[i]);
            d += d1 + 1;
            m = m + d1*a[i] - b[i];
        }
        cout << ans << endl;
    }
    return 0; 
}