#include <bits/stdc++.h>
using namespace std;

int a[500005], n;
int dp[50005][7];
map<int,int> t;

int go(int idx, int last){
    if(idx == n)return (t[last] == 6 ? 0 : 1e9);
    if(dp[idx][t[last]] != -1)return dp[idx][t[last]];
    int ans = 1e9;
    ans = go(idx + 1, last);
    if(t[last] == 0 && a[idx] == 4)ans = min(ans, go(idx + 1, t[4]));
    if(t[last] == 1 && a[idx] == 8)ans = min(ans, go(idx + 1, t[8]));
    if(t[last] == 2 && a[idx] == 15)ans = min(ans, go(idx + 1, t[15]));
    if(t[last] == 3 && a[idx] == 16)ans = min(ans, go(idx + 1, t[16]));
    if(t[last] == 4 && a[idx] == 23)ans = min(ans, go(idx + 1, t[23]));
    if(t[last] == 5 && a[idx] == 42)ans = min(ans, go(idx + 1, t[42]));
    ans = min(ans, go(idx + 1, last) + 1);
    return dp[idx][last] = ans;
}

int main(){
    t[0] = 0;
    t[4] = 1;
    t[8] = 2;
    t[15] = 3;
    t[16] = 4;
    t[23] = 5;
    t[42] = 6;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << go(0,0) << endl;
    return 0;
}