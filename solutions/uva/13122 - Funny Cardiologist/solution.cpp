#include <bits/stdc++.h>
using namespace std;

vector<int> x, y;
double d[256][256];
double dp[257][253];
int N;

double go(int i, int k){
    if(i == N - 1)return (k == 0 ? 0 : 1000005);
    if(dp[i][k] != -1.0)return dp[i][k];
    double ans = 1000005;
    for(int j = 0; j <= k && (j+1+i) < N; j++)
        ans = min(ans, go(i+j+1, k - j) + d[i][j+i+1]);
    return dp[i][k] = ans;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin >> n >> k){
        x.assign(n,0);
        y.assign(n,0);
        N = n;
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        for(int i = 0; i < 257; i++){
            for(int j = 0; j < 253; j++){
                dp[i][j] = -1.0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                d[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
            }
        }
        cout << fixed << setprecision(3) << go(0,k) << endl;
    }
    return 0;
}