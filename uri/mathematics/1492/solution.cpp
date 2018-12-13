#include <bits/stdc++.h>
#define endl '\n'
#define M 57
using namespace std;

string s;
long long dp[57][2][57];
long long f(int idx, bool top, int acc){

    if(idx == s.size())return acc;
    if(dp[idx][top][acc] != 0)return dp[idx][top][acc];
    int mmax = ( top ? s[idx] - '0' : 1);
    long long ans = 0;
    for(int i = 0; i <= mmax; i++){
        ans += f(idx + 1, top && i == mmax, acc + i);
    }
    return dp[idx][top][acc] = ans;
    
}

int main(){
    long long a, b;
    while(cin >> a >> b){
        bitset<M> v(a-1);
        s = v.to_string();
        memset(dp, 0, sizeof dp);
        a = f(0, true, 0);
        bitset<M> v1(b);
        s = v1.to_string();
        memset(dp, 0, sizeof dp);
        b = f(0, true, 0);
        
        cout << b - a << endl;
    }
    return 0;
}