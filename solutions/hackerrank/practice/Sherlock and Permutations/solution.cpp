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

const ll mod = 1e9 + 7;
const int Mxn = 1100;
ll dp[Mxn][Mxn];

void add(ll & a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,Mxn) {
        fori(j,0,Mxn) {
            if(i == 0 && j == 0) { dp[i][j] = 1; continue; }
            ll ans = 0;
            if(i-1 >= 0) add(ans, dp[i-1][j]);
            if(j-1 >= 0) add(ans, dp[i][j-1]);
            dp[i][j] = ans;
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m-1] << endl;
    }
    return 0; 
}