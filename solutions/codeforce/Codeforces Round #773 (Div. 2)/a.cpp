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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while (t--) {
        int x[3], y[3];
        fori(i,0,3) cin >> x[i] >> y[i];
        double ans = 0;
        if(y[0] == y[1] && y[2] < y[0]) ans = abs(x[0] - x[1]);
        if(y[0] == y[2] && y[1] < y[0]) ans = abs(x[0] - x[2]);
        if(y[1] == y[2] && y[0] < y[1]) ans = abs(x[1] - x[2]);
        cout << ans << endl;
    }
    return 0;
}