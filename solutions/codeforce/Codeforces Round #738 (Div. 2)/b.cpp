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

const int Mxn = 110;
int n; string s;
int dp[Mxn][4];

char get_char(int x) {
    return x == 0 ? 'B' : 'R';
}

void rec(int i, int c, string & ans) {
    if(i == n) return;
    int cur = dp[i][c];
    if(s[i] == '?') {
        int nc;
        if(cur == dp[i+1][c^1]) nc = c^1;
        else nc = c;
        ans += get_char(nc);
        rec(i+1, nc, ans);
    } else {
        int c = s[i] == 'B' ? 0 : 1;
        ans += s[i];
        rec(i+1, c, ans);
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        fore(i,0,n) dp[i][0] = dp[i][1] = 0;
        forr(i,n-1,0) {
            if(s[i] == '?') {
                dp[i][0] = min(dp[i+1][0] + 1, dp[i+1][1]);
                dp[i][1] = min(dp[i+1][1] + 1, dp[i+1][0]); 
            } else {
                int c = s[i] == 'B' ? 0 : 1;
                dp[i][0] = dp[i+1][c] + (c == 0);
                dp[i][1] = dp[i+1][c] + (c == 1);
            }
        }
        string ans;
        int mn = dp[0][0] < dp[0][1] ? 0 : 1;
        rec(0, mn, ans);
        cout << ans << endl;       
    }
    return 0; 
}