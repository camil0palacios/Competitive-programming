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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
ll x[N], p[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll a, b;
        cin >> n >> a >> b;
        x[0] = p[0] = 0;
        fore(i,1,n) cin >> x[i];
        fore(i,1,n) p[i] = p[i-1] + x[i];
        ll ans = 1e18;
        fore(i,0,n) {
            ans = min(ans, (a+b)*(x[i]-x[0]) + b*(p[n]-p[i]-(n-i)*x[i]));
        }
        cout << ans << endl;
    }
    return 0; 
}