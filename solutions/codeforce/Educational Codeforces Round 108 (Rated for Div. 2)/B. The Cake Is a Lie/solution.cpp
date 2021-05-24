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

const int Mxn = 105;
const int Mxk = 10005; 
bool dp[Mxn][Mxn][Mxk];

void cal() {
    fori(i,1,Mxn) 
        fori(j,1,Mxn)
            fori(k,0,Mxk) {
                if(i == 1 && j == 1) { dp[i][j][k] = k == 0; continue; }
                if(i > 1 && j <= k) dp[i][j][k] |= dp[i-1][j][k-j];
                if(j > 1 && i <= k) dp[i][j][k] |= dp[i][j-1][k-i];
            }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << (dp[n][m][k] ? "YES" : "NO") << endl;
    }
    return 0; 
}