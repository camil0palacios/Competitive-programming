#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 1e6 + 5;
bool sieve[MXN];
vector<ll> p;

void cal() {
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(long long i = 2; i < MXN; i++) {
        if(sieve[i]) {
            p.emplace_back(i);
            for(long long j = i * i; j < MXN; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

unordered_map<long long, long long> dp[40];

long long Dp(int idx, long long num, vector<pair<int,int>>& my_primes) {
    if(idx == my_primes.size()) return num;
    if(dp[idx].count(num)) return dp[idx][num];
    long long ans = Dp(idx + 1, num, my_primes);
    long long p = 1;
    for(int i = 0; i < my_primes[idx].second; i++) {
        p *= my_primes[idx].first;
        ans += Dp(idx + 1, num * p, my_primes);
    }
    return dp[idx][num] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    int t;
    cin >> t;
    while(t--) {
        long long n, tmp;
        cin >> n;
        tmp = n;
        vector<pair<int,int>> my_primes;
        for(int i = 0; i < p.size() && p[i]*p[i] <= n; i++) {
            if(n % p[i] == 0) {
                int cnt = 0;
                while(n % p[i] == 0) {
                    n /= p[i];
                    cnt++;
                }
                my_primes.emplace_back(p[i], cnt);
            }
        } 
        if(n > 1) my_primes.emplace_back(n, 1);
        for(int i = 0; i < my_primes.size(); i++) {
            dp[i].clear();
        }
        long long ans = Dp(0, 1, my_primes) - tmp;
        if(ans == tmp) cout << "perfect";
        else if(ans < tmp) cout << "deficient";
        else cout << "abundant";
        cout << endl;
    }
    return 0;
}