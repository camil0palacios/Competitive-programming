#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxm = 1001;
string s;
int m;
int dp[Mxm][12][12];
vi ans;

int go(int i, int m1, int lst) {
    if(i == m) return 1;
    if(dp[i][m1][lst] != -1) return dp[i][m1][lst];
    fore(j,1,10) {
        if(s[j-1] == '0' || lst == j) continue;
        if(j > m1 && go(i+1, j - m1, j)) {
            ans.eb(j);
            return dp[i][m1][lst] = 1;
        }
    }
    return dp[i][m1][lst] = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> m;
    memset(dp, -1, sizeof dp);
    if(go(0,0,0)) {
        reverse(all(ans));
        cout << "YES" << endl;
        for(auto & i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    } 
    else cout << "NO" << endl;
    return 0; 
}