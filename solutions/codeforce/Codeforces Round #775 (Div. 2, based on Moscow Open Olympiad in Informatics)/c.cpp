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

const int Mxn = 1e5 + 5;
ll s[Mxn], cnt[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    fori(i,0,n) fori(j,0,m) cin >> a[i][j];
    ll ans = 0;
    fori(i,0,n) {
        fori(j,0,m) {
            int col = a[i][j];
            ans += i*cnt[col] - s[col];
        }
        fori(j,0,m) {
            int col = a[i][j];
            cnt[col]++;
            s[col] += i;
        }
    }
    memset(s, 0, sizeof s);
    memset(cnt, 0, sizeof cnt);
    fori(j,0,m) {
        fori(i,0,n) {
            int col = a[i][j];
            ans += j*cnt[col] - s[col];
        }
        fori(i,0,n) {
            int col = a[i][j];
            cnt[col]++;
            s[col] += j;
        }
    }
    cout << ans << endl;
    return 0; 
}