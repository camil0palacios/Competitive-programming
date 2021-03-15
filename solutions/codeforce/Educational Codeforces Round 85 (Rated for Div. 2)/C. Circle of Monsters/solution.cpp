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

const int Mxn = 3e5 + 5;
ll a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i] >> b[i];
        ll s = 0;
        fori(i,0,n) s += max(0ll, a[(i+1)%n] - b[i]);
        ll ans = 1e18;
        fori(i,0,n) {
            ans = min(ans, s - max(0ll, a[i] - b[(i-1+n)%n]) + a[i]);
        }
        cout << ans << endl;
    }
    return 0; 
}