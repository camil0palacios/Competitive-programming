#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 101;
int dp[MAXN], a[MAXN], n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)dp[i] = MAXN;
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i < n; i++){
        if(!a[i]){
            if(!a[i-1])dp[i] = min(dp[i], dp[i-1] + 1);
            if(!a[i-2])dp[i] = min(dp[i], dp[i-2] + 1);
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}