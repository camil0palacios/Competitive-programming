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

const int oo = 1e9;
const int Mxn = 1e5 + 5;
const int Mxa = 513;
int a[Mxn];
int dp[Mxn][Mxa];
int pos[Mxn][Mxa];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fore(i,1,n) cin >> a[i];
    fore(i,1,n) fori(x,0,Mxa) pos[i][x] = oo;
    fore(i,1,n) {
        fori(x,0,512) {
            if(a[i] == x) {
                dp[i][x] = 1;
                pos[i][x] = min(pos[i][x], x);
            } else {
                if(pos[i-1][x^a[i]] < a[i]) {
                    dp[i][x] = dp[i-1][x] || dp[i-1][x^a[i]];
                    if(dp[i-1][x^a[i]]) pos[i][x] = min(pos[i][x], a[i]);
                    if(dp[i-1][x]) pos[i][x] = min(pos[i][x], pos[i-1][x]);
                } else {
                    dp[i][x] = dp[i-1][x];
                    pos[i][x] = pos[i-1][x];
                }
            }
        }
    }
    vi ans = {0};
    fori(i,1,Mxa) {
        if(dp[n][i]) ans.eb(i);
    }
    cout << sz(ans) << endl;
    for(int i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}