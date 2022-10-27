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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll oo = 1e14;
const int Mxn = 2e5 + 5;
int n;
ll a[Mxn], b[Mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        fore(i,1,n) cin >> a[i];
        fore(i,1,n) cin >> b[i];
        ll a1 = 1e9, a2 = 1e9;
        ll b1 = 1e9, b2 = 1e9;
        fore(i,1,n) {
            a1 = min(a1, abs(a[1] - b[i]));
            a2 = min(a2, abs(a[n] - b[i]));
            b1 = min(b1, abs(b[1] - a[i]));
            b2 = min(b2, abs(b[n] - a[i]));
        }
        ll ans = min({
            abs(a[1]-b[1]) + abs(a[n]-b[n]),
            abs(a[1]-b[n]) + abs(a[n]-b[1]),
            min(a1 + b1, abs(a[1]-b[1])) + a2 + b2,
            min(a1 + b2, abs(a[1]-b[n])) + a2 + b1,
            min(a2 + b1, abs(a[n]-b[1])) + a1 + b2,
            min(a2 + b2, abs(a[n]-b[n])) + a1 + b1,
            a1 + a2 + b1 + b2
        });
        cout << ans << endl;
    }
    return 0;
}