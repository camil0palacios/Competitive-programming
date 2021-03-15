#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
const int n = 100, m = 26 * n;
ll dp[n + 1][m + 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int s = 0; s <= m; s++) {
            for(int j = 0; j < 26; j++) {
                if(j <= s) 
                    dp[i][s] = (dp[i][s] + dp[i - 1][s - j]) % mod;
            }
        }  
    }
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int sum = 0;
        for(int i = 0; i < s.size(); i++) sum += s[i] - 'a';
        cout << dp[s.size()][sum] - 1 << endl;
    }
    return 0;
}