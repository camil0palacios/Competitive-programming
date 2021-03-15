#include <bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long
using namespace std;

string n, res;
int s;
int dp[21][163][2];

bool dptop(int idx, int sum, bool start){
    if(idx == n.size()) return sum <= s;
    if(dp[idx][sum][start] != -1) return dp[idx][sum][start];
    int low = start ? 0 : n[idx] - '0';
    for(int i = low; i <= 9; i++) {
        if(dptop(idx + 1, sum + i, start || i != (n[idx] - '0'))) {
            res[idx] = char(i + '0');
            return dp[idx][sum][start] = 1;
        }
    }
    return dp[idx][sum][start] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll x, y = 0;
        cin >> x >> s;
        n = res = string(20, '0');
        string tmp = to_string(x);
        for(int i = tmp.size() - 1, j = 19; i >= 0; i--, j--) {
            n[j] = tmp[i];
        }
        memset(dp, -1, sizeof dp);
        dptop(0, 0, 0);
        for(int i = 0; i < 20; i++) {
            y = y * 10 + (res[i] - '0');
        }
        cout << y - x << endl;
    }
    return 0;
}