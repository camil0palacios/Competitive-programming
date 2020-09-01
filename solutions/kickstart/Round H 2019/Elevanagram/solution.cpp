#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[10][905][205], a[9];

bool go(int idx, int sum, int k){
    if(idx == 9)return sum % 11 == 0 && k == 0;
    if(dp[idx][sum][k] != -1)return dp[idx][sum][k];
    bool ans = 0;
    for(int i = 0; i <= a[idx]; i++){
        if(sum - i*(idx + 1)*2 >= 0 && k - i >= 0){
            ans |= go(idx + 1, sum - i*(idx + 1)*2, k - i);
        }
    }
    return dp[idx][sum][k] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int cnt = 0, sum = 0;
        for(int i = 0; i < 9; i++){
            cin >> a[i];
            sum += a[i]*(i + 1);
            cnt += a[i];
        }
        memset(dp, -1, sizeof dp);
        int ans = go(0, sum, cnt / 2);
        cout << "Case #" << cs << ": " << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}