#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

int dp[3005][3005];

int main(){
    string s, t;
    cin >> s >> t;
    //dp[i][j] = max(dp[i][j+1], dp[i+1][j], dp[i+1][j+1] + 1 if s[i] == s[j])
    int n = s.size(), m = t.size();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1; 
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string ns;
    while(i >= 1 && j >= 1){
        if(s[i-1] == t[j-1]){
            ns += s[i-1];
            i = i-1, j = j-1;
        }
        else if(dp[i-1][j] > dp[i][j-1])i = i-1;
        else j = j-1;
    }
    reverse(ns.begin(), ns.end());
    cout << ns << endl;
    return 0;   
}