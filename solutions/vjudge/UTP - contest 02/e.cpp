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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 85;
int n, m;
string a, b;
int dp[Mxn][Mxn];
set<string> r[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        n = sz(a), m = sz(b);
        forr(i,n,0) {
            forr(j,m,0) {
                int & ans = dp[i][j];
                ans = 0;
                r[i][j].clear();
                if(i == n || j == m) continue;
                if(a[i] == b[j]) ans = dp[i+1][j+1] + 1;
                else ans = max(ans, max(dp[i+1][j], dp[i][j+1]));
                if(a[i] == b[j] && ans == dp[i+1][j+1] + 1) {
                    string x = string(1, a[i]);
                    for(auto & s : r[i+1][j+1]) {
                        string t = x + s;
                        r[i][j].insert(t);
                    }
                    if(!sz(r[i+1][j+1])) r[i][j].insert(x);
                }
                else {
                    if(ans == dp[i+1][j]) r[i][j].insert(all(r[i+1][j]));
                    if(ans == dp[i][j+1]) r[i][j].insert(all(r[i][j+1]));
                } 
            }
        }
        // cout << dp[0][0] << endl;
        for(auto & s : r[0][0]) cout << s << endl;

    }
    return 0; 
}