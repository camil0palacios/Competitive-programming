#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 110;
const int MXK = 1e5 + 5;
int n, k;
int a[MXN];
int dp[MXK];

void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
} 

void sub_self(int& a, int b) {
    a -= b;
    if(a < 0) {
        a += mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vector<int> fake(k + 1);    
        for(int j = k; j >= 0; j--) {
            int tmp = dp[j];
            int l = j + 1, r = j + min(a[i], k - j);
            if(l <= r) {
                add_self(fake[l], tmp);
                if(r + 1 <= k) {
                    sub_self(fake[r + 1], tmp);
                }
            }
        }
        int ps = 0;
        for(int j = 0; j <= k; j++) {
            add_self(ps, fake[j]);
            add_self(dp[j], ps);
        }
    }
    cout << dp[k] << endl;
    return 0;
}