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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;
const int oo = 1e9;
const int Mxn = 1010;
ll dp[Mxn][3];
int a[26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    fori(i,0,26) cin >> a[i];
    fore(i,0,n) dp[i][2] = oo;
    dp[n][0] = 1;
    dp[n][2] = 0;
    forr(i,n-1,0) {
        set<int> m;
        fori(j,i,n) {
            m.insert(s[j]-'a');
            bool ok = 1;
            for(auto & x : m) ok &= j-i+1 <= a[x];
            if(ok) {
                dp[i][0] += dp[j+1][0];
                dp[i][0] %= mod;
                if(dp[i][0]) {
                    dp[i][1] = max(dp[i][1], max(dp[j+1][1], 1ll*j-i+1));
                    dp[i][2] = min(dp[i][2], dp[j+1][2] + 1);
                } 
            }
        }
    }
    fori(i,0,3) cout << dp[0][i] << endl;
    return 0; 
}