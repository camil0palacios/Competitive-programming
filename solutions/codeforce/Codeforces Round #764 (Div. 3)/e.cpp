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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1e5 + 5;
int n, m;
string a[Mxn], s;
int dp[Mxn];
vector<vi> ans;

map<string, pair<int,int>> to; 

bool go(int i) {
    if(i == m) return 1;
    if(dp[i] != -1) return dp[i];
    if(i+1 < m && to.count(s.substr(i, 2)) && go(i+2)) {
        auto p = to[s.substr(i, 2)];
        vi tmp({p.sd, p.sd+1, p.ft});
        ans.eb(tmp);
        return dp[i] = 1;
    }
    if(i+2 < m && to.count(s.substr(i, 3)) && go(i+3)) {
        auto p = to[s.substr(i, 3)];
        vi tmp({p.sd, p.sd+2, p.ft});
        ans.eb(tmp);
        return dp[i] = 1;
    }
    return dp[i] = 0;
}

void sol() {
    cin >> n >> m;
    to.clear();
    fori(i,0,n) cin >> a[i];
    cin >> s;
    fori(i,0,n) {
        fori(j,0,m-1) {
            to[a[i].substr(j, 2)] = mp(i, j);
            if(j+2 < m)
                to[a[i].substr(j, 3)] = mp(i, j);
        }
    }
    ans.clear();
    memset(dp, -1, sizeof dp);
    if(go(0)) {
        reverse(all(ans));
        cout << sz(ans) << endl;
        for(auto & v : ans) {
            cout << v[0]+1 << ' ' << v[1]+1 << ' ' << v[2]+1 << endl;
        }
    } else cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
    return 0; 
}