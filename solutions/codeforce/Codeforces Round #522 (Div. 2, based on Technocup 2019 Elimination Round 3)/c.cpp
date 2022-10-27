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
int n;
int a[Mxn];
int dp[Mxn][5], ans[Mxn];

int go(int i, int lst) {
    if(i < 0) return 1;
    if(dp[i][lst] != -1) return dp[i][lst];
    fori(j,0,5) {
        bool ok = 0;
        if(a[i] < a[i+1] && j < lst && go(i-1, j)) ok = 1;
        else if(a[i] > a[i+1] && j > lst && go(i-1, j)) ok = 1;
        else if(a[i] == a[i+1] && j != lst && go(i-1, j)) ok = 1;
        if(ok) {
            ans[i] = j;
            return dp[i][lst] = 1;
        }
    }
    return dp[i][lst] = 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    fori(i,0,n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    bool ok = 0;
    fori(i,0,5) {
        if(go(n-2, i)) {
            ans[n-1] = i; 
            ok = 1;
            break;
        }
    }
    if(ok) {
        fori(i,0,n) cout << ans[i]+1 << ' ';
        cout << endl;
    } else cout << -1 << endl;
    return 0; 
}