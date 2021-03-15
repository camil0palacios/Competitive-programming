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
typedef vector<ll> vll;

const int Mxn = 1005;
int n, p;
string s;
int dp[Mxn][27][27][2];
string ans;

bool go(int idx, int prv, int lst, bool bot) {
    if(idx == n) return bot != 1;
    int & res = dp[idx][prv][lst][bot];
    if(res != -1) return res;
    int mn = bot ? s[idx]-'a' : 0;
    for(int i = mn; i < p; i++) {
        if(i != prv && i != lst && go(idx + 1, lst, i, bot && i == mn)) {
            ans[idx] = char(i + 'a');
            return res = 1;
        } 
    }
    return res = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> p >> s;
    memset(dp, -1, sizeof dp);
    ans = string(n, 'a');
    if(go(0,26,26,1)) cout << ans << endl;
    else cout << "NO" << endl;
    return 0; 
}