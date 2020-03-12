#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int h[100005], dp[100005], n, k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + abs(h[i] - h[i-1]);
        for(int j = 2; j <= k; j++){
            if(i-j >= 0){
                dp[i] = min(dp[i], dp[i-j] + abs(h[i-j] - h[i]));
            }
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}