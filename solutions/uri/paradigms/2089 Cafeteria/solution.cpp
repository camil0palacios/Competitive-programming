#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int Mxn = 1010;
const int Mxv = 1e5 + 5;
int a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v, n;
    while(cin >> v >> n, v && n) {
        // dp[i][val] = dp[i - 1][val] | dp[i - 1][val - a[i]]
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> dp(v + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            vector<int> dp_new(v + 1);
            for(int val = 0; val <= v; val++) {
                dp_new[val] = dp[val];
                if(a[i] <= val) dp_new[val] |= dp[val - a[i]];
            }
            dp = dp_new;
        }
        cout << (dp[v] ? "sim" : "nao") << endl;
    }

    return 0;
}