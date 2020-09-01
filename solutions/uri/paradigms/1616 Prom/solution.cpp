#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const ll mod = 1000000007;

int a, b;
ll dp[1100][1100];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> a >> b && (a || b)) {
        for(int i = a; i >= 0; i--) {
            for(int j = b; j >= 0; j--) {
                if(i == a) dp[i][j] = (j == b);
                else dp[i][j] = (dp[i + 1][j] * j + dp[i + 1][j + 1] * (b - j)) % mod;
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}
