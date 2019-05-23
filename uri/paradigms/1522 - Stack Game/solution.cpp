#include <bits/stdc++.h>
using namespace std;

int dp[105][105][105];
int a[105], b[105], c[105], n;

bool go(int i, int j, int k){
    if(i == k && j == k && k == n)return 1;
    if(dp[i][j][k] != -1)return dp[i][j][k];
    int ans = 0;
    if(i < n && a[i]%3 == 0)
        ans |= go(i+1,j,k);
    if(j < n && b[j]%3 == 0)
        ans |= go(i,j+1,k);
    if(k < n && c[k]%3 == 0)
        ans |= go(i,j,k+1);
    if(i < n && j < n && (a[i]+b[j])%3 == 0)
        ans |= go(i+1,j+1,k);
    if(j < n && k < n && (b[j]+c[k])%3 == 0)
        ans |= go(i,j+1,k+1);
    if(i < n && k < n && (a[i]+c[k])%3 == 0)
        ans |= go(i+1,j,k+1);
    if(i < n && j < n && k < n && (a[i]+b[j]+c[k]) % 3 == 0)
        ans |= go(i+1,j+1,k+1);

    return dp[i][j][k] = ans;
}

int main(){

    while(cin >> n){
        if(n == 0)break;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        memset(dp, -1, sizeof dp);
        cout << go(0,0,0) << endl;
    }
    return 0;
}