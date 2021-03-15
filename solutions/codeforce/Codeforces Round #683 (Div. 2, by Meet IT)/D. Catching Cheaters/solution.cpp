#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 5050;
int dp[MXN][MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;
    int mx = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) - 1;
            if(dp[i][j] < 0) dp[i][j] = 0;
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 2);
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx << endl;
    return 0; 
}