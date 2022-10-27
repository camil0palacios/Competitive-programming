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
int n, m;
vector<vi> a;

bool check(int x) {
    vi fr(m, 0);
    int p = 0;
    fori(i,0,n) {
        int cnt = 0;
        fori(j,0,m) {
            if(a[i][j] >= x) {
                fr[j] = 1;
                cnt++;     
            }
        }
        if(cnt > 1) p = 1;
    }
    if(!p && m > 1) return 0;
    bool ok = 1;
    fori(i,0,m) ok &= fr[i];
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.assign(n, vi(m, 0));
        fori(i,0,n) fori(j,0,m) cin >> a[i][j];
        int l = 0, r = 1e9, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // cout << mid << endl;
            if (check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}