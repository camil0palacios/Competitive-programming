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

const int oo = 1e9;
const int N = 11;
string s;
string a[N];
int dp[110];
vi g[110];

int go(int i) { 
    if(i == sz(s)) return 0;
    int & ans = dp[i];
    if(ans == -1) {
        ans = oo;
        for(int x : g[i]) {
            fore(j,i+1,i+sz(a[x])) {
                ans = min(ans, go(j) + 1);
            }
        }
    }
    return ans;
}

void rec(int i, vii & ans) {
    if(i == sz(s)) return;
    for(int x : g[i]) {
        fore(j,i+1,i+sz(a[x])) {
            if(go(i) == go(j) + 1) {
                ans.eb(x, i);
                rec(j, ans);
                return;
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> s >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,sz(s)) g[i].clear();
        fori(i,0,sz(s)) {
            fori(j,0,n) {
                if(s.substr(i, sz(a[j])) == a[j]) { 
                    g[i].eb(j);
                }
            }
        }
        memset(dp, -1, sizeof dp);
        if(go(0) != oo) {
            cout << go(0) << endl;
            vii ans;
            rec(0, ans);
            for(auto [w, p] : ans) cout << w+1 << ' ' << p+1 << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}