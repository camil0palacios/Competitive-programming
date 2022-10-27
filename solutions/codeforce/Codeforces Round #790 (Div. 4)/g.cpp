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
vi g[N];
string s;
int ans;
int dp[N][2];

int color(char c) {
    return c == 'W' ? 1 : 0;
}

void dfs(int u) {
    dp[u][color(s[u])] = 1;
    for(auto & v: g[u]) {
        dfs(v);
        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][1];
    }
    if(dp[u][0] == dp[u][1]) ans++;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) {
            g[i].clear(); 
            dp[i][0] = dp[i][1] = 0;
        }
        fori(i,1,n) {
            int p; cin >> p; p--;
            g[p].eb(i);
        }
        cin >> s;
        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    return 0; 
}