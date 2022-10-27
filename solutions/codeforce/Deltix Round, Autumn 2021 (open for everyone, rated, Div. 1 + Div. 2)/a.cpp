#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

// typedef __int128_t i128; only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 20;
ll a[Mxn], b[Mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        ll ans = 0;        
        fori(i,0,n) {
            fori(j,0,n) b[j] = a[j]; 
            fori(j,0,n) {
                if(i == j) continue;
                while(b[j] % 2 == 0) b[i] *= 2, b[j] /= 2;
            }
            ll tmp = 0;
            fori(j,0,n) tmp += b[j];
            ans = max(ans, tmp);
        }
        cout << ans << endl; 
    }
    return 0;
}