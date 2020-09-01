#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    char s[5005];
    while(true){
        scanf("%s", s);
        if(s[0] == '0') break;
        int n = strlen(s);
        ll dp[n + 1];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            int x = s[i - 2] - '0', y = s[i - 1] - '0';
            if(x == 1 || (x == 2 && y <= 6)) dp[i] += dp[i - 2];
            if(y != 0) dp[i] += dp[i - 1]; 
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}