#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, h[100005], dp[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + abs(h[i-1] - h[i]);
        if(i-2 >= 0){
            dp[i] = min(dp[i], dp[i-2] + abs(h[i-2] - h[i]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}