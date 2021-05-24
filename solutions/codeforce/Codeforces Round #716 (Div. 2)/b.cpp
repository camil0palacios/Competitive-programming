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

const int mod = 1e9 + 7;
const int Mxn = 1e5 + 5;
const int Mxk = 25;
ll c[Mxk][Mxk];
ll dp[Mxn][Mxk];

void cal() {
    c[0][0] = 1;
    fore(i,1,Mxk) {
        c[i][0] = c[i][i] = 1;
        fori(j,1,i) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
    memset(dp, 0, sizeof dp);
    int n = Mxn-1, K = Mxk-1;
    dp[0][0] = 1;
    fore(i,1,n) {
        fore(k,0,K) {
            fore(j,0,k) {
                dp[i][k] = (dp[i][k] + (dp[i-1][k-j]*c[k][j]) % mod) % mod;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        int n, K;
        cin >> n >> K;
        cout << dp[n][K] << endl;
    }
    return 0; 
}