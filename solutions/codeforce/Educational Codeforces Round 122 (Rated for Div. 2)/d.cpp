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
const int Mxn = 1100;
int dp[Mxn][13005];
int b[Mxn], c[Mxn];
int p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,0,Mxn) p[i] = oo;
    p[1] = 0;
    fori(i,1,Mxn) {
        fore(j,1,i) {
            if(i+i/j >= Mxn) continue;
            p[i+i/j] = min(p[i+i/j], p[i] + 1);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        k = min(k, 13000);
        fore(i,1,n) cin >> b[i];
        fore(i,1,n) cin >> c[i];
        fore(i,1,n) fore(j,0,k) dp[i][j] = -oo;
        fore(i,0,k) dp[0][i] = 0;
        fore(i,1,n) {
            fore(j,0,k) {
                dp[i][j] = dp[i-1][j];
                if(j >= p[b[i]]) 
                    dp[i][j] = max(dp[i][j], dp[i-1][j-p[b[i]]] + c[i]); 
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0; 
}