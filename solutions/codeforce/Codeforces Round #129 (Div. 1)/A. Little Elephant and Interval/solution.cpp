#include <bits/stdc++.h>
using namespace std;

long long dp[19][2][2][10][10];

long long dptop(string & s, int idx, bool top, bool take, int first, int last){
    if(idx == s.size())return first == last;
    if(dp[idx][top][take][first][last] != -1)return dp[idx][top][take][first][last];
    int mmax = (top ? s[idx]-'0' : 9);
    long long ans = 0;
    for(int i = 0; i <= mmax; i++){
        ans += dptop(s,idx+1,top && (i == mmax),take || (i != 0),(!take && i != 0 ? i : first), i);
    }
    return dp[idx][top][take][first][last] = ans;
}

int main(){
    long long x;
    string a,b;
    cin >> x >> b;
    a = to_string(x-1);
    memset(dp, -1, sizeof dp);
    x = dptop(a,0,1,0,0,0);
    memset(dp, -1, sizeof dp);
    cout << dptop(b,0,1,0,0,0) - x << endl;
    return 0;
}