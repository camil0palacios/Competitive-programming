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
int p[N][26];

void solve() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    fori(i,0,n) {
        fori(j,0,26) {
            p[i+1][j] = 0;
            p[i+1][j] = p[i][j];
        }
        p[i+1][s[i]-'A']++;
    }
    int ans = 0;
    fori(i,0,q) {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        fori(j,0,26) cnt += ((p[r][j] - p[l-1][j]) & 1);
        ans += cnt <= 1;
    }
    cout << ans << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0; 
}