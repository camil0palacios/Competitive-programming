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
const int Mxn = 2e5 + 5;
ll a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, B, x, y;
        cin >> n >> B >> x >> y;
        fore(i,1,n) a[i] = -oo;
        fore(i,1,n) {
            if(a[i-1] + x <= B) a[i] = max(a[i], a[i-1] + x);
            if(a[i-1] - y <= B) a[i] = max(a[i], a[i-1] - y);
        }
        ll ans = 0;
        fore(i,1,n) ans += a[i];
        cout << ans << endl; 
    }
    return 0; 
}