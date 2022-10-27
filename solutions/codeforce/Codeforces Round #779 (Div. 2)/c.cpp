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

const int Mxn = 2e5 + 5;
int a[Mxn];

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    fori(i,0,n) cin >> a[i], cnt += a[i] == 1;
    if(cnt != 1) {
        cout << "NO" << endl;
        return;
    }
    int p = find(a, a+n, 1) - a;
    rotate(a, a+p, a+n);
    fori(i,1,n) {
        if(a[i] - a[i-1] > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}