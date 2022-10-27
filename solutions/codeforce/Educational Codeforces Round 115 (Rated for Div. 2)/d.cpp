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

const int Mxn = 2e5 + 5;
int tc[Mxn], df[Mxn];
int a[Mxn], b[Mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        fore(i,0,n) tc[i] = df[i] = 0;
        fori(i,0,n) {
            cin >> a[i] >> b[i];
            tc[a[i]]++;
            df[b[i]]++;
        }
        ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
        fori(i,0,n) {
            ans -= 1ll * (tc[a[i]] - 1) * (df[b[i]] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}