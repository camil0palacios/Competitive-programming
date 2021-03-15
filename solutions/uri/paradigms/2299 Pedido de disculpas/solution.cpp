#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int c, f, cs = 0;
    while(cin >> c >> f, c && f) {
        vector<int> a(f + 1), b(f + 1);
        for(int i = 1; i <= f; i++) {
            cin >> a[i] >> b[i];
        }
        vector<int> dp(c + 1);
        for(int i = 1; i <= f; i++) {
            vector<int> dp_new(c + 1);
            for(int j = 0; j <= c; j++) {
                dp_new[j] = dp[j];
                if(a[i] <= j) dp_new[j] = max(dp_new[j], dp[j - a[i]] + b[i]);
            }
            dp = dp_new;
        }
        cout << "Teste " << ++cs << endl;
        cout << dp[c] << endl << endl;
    }
    return 0;
}