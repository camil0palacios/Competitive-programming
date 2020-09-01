#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 55;
int n, a[MXN];
bool sieve[MXN];
int msks[15], dp[MXN][1 << 16];
vector<int> p;

void fill() {
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i < MXN; i++) {
        if(sieve[i] == 1) {
            p.emplace_back(i);
            for(int j = i * i; j < MXN; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

void getPrimes(int idx, int num) {
    int msk = 0;
    for(int i = 0; i < p.size() && p[i] * p[i] <= num; i++) {
        if(num % p[i] == 0) {
            while(num % p[i] == 0){
                num /= p[i];
            }
            msk |= (1 << i);
        }
    }
    if(num > 1){
        for(int i = 0; i < p.size(); i++) {
            if(num == p[i]){
                msk |= (1 << i);
                break;
            }
        }
    }
    msks[idx] = msk;
}

int dfs(int i, int msk) {
    if(i == n)return 0;
    if(dp[i][msk] != -1)return dp[i][msk];
    int ans = dfs(i + 1, msk);
    if(!(msks[i] & msk)) {
        ans = max(ans, dfs(i + 1, msk | msks[i]) + 1);
    }
    return dp[i][msk] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill();
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            getPrimes(i, a[i]);
        }
        memset(dp, -1, sizeof dp);
        int ans = dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}