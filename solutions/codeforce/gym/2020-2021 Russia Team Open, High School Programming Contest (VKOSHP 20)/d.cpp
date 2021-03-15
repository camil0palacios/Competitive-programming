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

const int Mxn = 16;
int n, k;
ll dp[Mxn][Mxn], dp2[Mxn][Mxn];

ll comb(int x, int c) {
    if(x == 0) return 1;
    if(dp2[x][c] != -1) return dp2[x][c];
    ll ans = comb(x-1, c);
    if(c-1 >= 0) ans += comb(x, c-1);
    return dp2[x][c] = ans;
}

ll go(int s, int l) {
    if(s == n) return 1;
    if(l > n) return 0;
    if(dp[s][l] != -1) return dp[s][l];
    ll ans = 0;
    fore(i,0,(n-s)/l) 
        ans += go(s + i*l, l+1)*comb(i, k-1);
    return dp[s][l] = ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    cout << go(0, 1) << endl;
    return 0; 
}