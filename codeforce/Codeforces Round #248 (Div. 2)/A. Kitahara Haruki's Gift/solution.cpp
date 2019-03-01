#include <bits/stdc++.h>
using namespace std;

int dp[100][20000];
int sum;

bool go(vector<int> &v, int i, int acc){
    if(i == v.size())return acc == sum;
    if(dp[i][acc] != -1)return dp[i][acc];
    bool ans = 0;
    if(acc + v[i] <= sum)ans = max(ans, go(v, i + 1, acc + v[i]));
    ans = max(ans, go(v, i + 1, acc));
    return dp[i][acc] = ans;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        sum = 0;
        vector<int> v(n);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
            v[i] /= 100;
        }
        if((sum/100) % 2){
            cout << "NO" << endl;
        } else {
            sum = (sum/100)/2;
            bool sol = go(v, 0, 0);
            cout << (sol ? "YES" : "NO") << endl;
        }
    }
    return 0;
}