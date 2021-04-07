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
const int Mxk = 25;
char a[Mxn];
ll dp[Mxn][Mxk][3];

int to(char c) {
    if(c == 'H') return 0;
    if(c == 'P') return 1;
    return 2;
}

int battle(int x, int y) {
    return (x == 0 && y == 2) || (x == 1 && y == 0) || (x == 2 && y == 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    fori(i,0,n) cin >> a[i];    
    forr(i,n-1,0) {
        fore(j,0,k) {
            fori(x,0,3) {
                ll & ans = dp[i][j][x];
                ans = dp[i+1][j][x] + battle(x, to(a[i]));
                if(j) {
                    fori(y,0,3) {
                        if(x == y) continue;
                        ans = max(ans, dp[i+1][j-1][y] + battle(y, to(a[i])));
                    }
                }
            }
        }
    }
    ll mx = 0;
    fori(i,0,n) mx = max(mx, dp[0][k][i]);
    cout << mx << endl;
    return 0; 
}