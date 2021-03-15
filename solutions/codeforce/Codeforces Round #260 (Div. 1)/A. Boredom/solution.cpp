#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];
int cnt[MXN];
ll dp[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    dp[1] = 1LL*cnt[1];
    for(int i = 2; i < MXN; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL*i*cnt[i]);
    }
    cout << dp[MXN - 1] << endl;
    return 0; 
}