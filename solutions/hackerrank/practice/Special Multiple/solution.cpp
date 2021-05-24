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

int n;
int dp[100][2][505];
string ans;

int go(int idx, bool nine, int r) {
    if(idx == 100) return nine && r == 0;
    if(dp[idx][nine][r] != -1) return dp[idx][nine][r];
    if(go(idx+1, nine, (r*10) % n)) {
        ans += '0';
        return dp[idx][nine][r] = 1;
    }
    if(go(idx+1, nine | 1, (r*10 + 9) % n)) {
        ans += '9';
        return dp[idx][nine][r] = 1;
    }
    return dp[idx][nine][r] = 0;
}

void solve() {
    cin >> n;
    ans.clear();
    memset(dp, -1, sizeof dp);
    go(0,0,0);
    reverse(all(ans));
    int k = 0;
    fori(i,0,sz(ans)) {
        k = i;
        if(ans[i] != '0') break;
    }
    cout << ans.substr(k) << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve(); 
    return 0; 
}