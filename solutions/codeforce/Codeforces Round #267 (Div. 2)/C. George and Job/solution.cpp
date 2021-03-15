#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const ll oo = 1e18;
int n, m, k;
ll dp[5050][5050];
ll p[5050];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        p[i] = p[i - 1] + x;
    }
    fori(i,0,n+1) fori(j,0,k+1) dp[i][j] = -oo;
    fori(i,0,n+1) dp[i][k] = 0;
    // dp[i][k] = max(dp[i+1][k], dp[i + m][k + 1] + p[i + m - 1] - p[i - 1])
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i + 1][j];
            if(i + m <= n+1  && j < k) {
                dp[i][j] = max(dp[i][j], dp[i + m][j + 1] + p[i + m - 1] - p[i - 1]);
            }
        } 
    }
    cout << dp[1][0] << endl;
    return 0; 
}