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

const int mod = 1e9 + 7;
const int Mxn = 5005;
int dp[Mxn][Mxn];

void add(int & a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
}

int go(int b, int s) {
    if(b == 0) return 1;
    if(dp[b][s] != -1) return dp[b][s];
    int ans = 0;
    if(s > 1) ans = (2*go(b, s - 1)) % mod;
    if(b - s >= 0) ans = (ans + go(b - s, s)) % mod;
    if(s > 2) ans = (ans - go(b, s - 2) + mod) % mod;
    return dp[b][s] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int S, B;
    cin >> S >> B;
    memset(dp, -1, sizeof dp);
    cout << go(B - S, S) << endl;
    return 0; 
}