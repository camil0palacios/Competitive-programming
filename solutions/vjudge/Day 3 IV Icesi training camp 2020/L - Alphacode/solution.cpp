#include <string>
#include <iostream>
#define endl '\n'
#define ull long long
using namespace std;

const int MXN = 1e5 + 5;
string s;
int n;
ull dp[MXN];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> s && s != "0") {
        n = s.size();
        for(int i = 0; i <= n; i++) dp[i] = 0;
        dp[n] = 1; dp[n - 1] = s[n - 1] != '0';
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] != '0') dp[i] = dp[i + 1];
            int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(x >= 10 && x <= 26)
                dp[i] += dp[i + 2];
        }
        cout << dp[0] << endl;
    }
    return 0;
}