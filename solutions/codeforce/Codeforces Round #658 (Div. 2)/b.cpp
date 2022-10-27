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

const int Mxn = 1e5 + 5;
int n;
int a[Mxn];
int dp[Mxn][2];

int go(int i, bool t) {
    if(i == n-1) return t;
    if(dp[i][t] != -1) return dp[i][t];
    int ans = 0;
    if(a[i] == 1) ans = go(i+1, t^1);
    else if(t) ans = max(go(i+1, t), go(i+1, t^1));
    else ans = min(go(i+1, t), go(i+1, t^1));
    return dp[i][t] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fore(i,0,n) dp[i][0] = dp[i][1] = -1;
        cout << (go(0, 1) ? "First" : "Second") << endl;
    }
    return 0; 
}