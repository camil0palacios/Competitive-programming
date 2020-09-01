#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
const int MXN = 1e6 + 5;
int pow_2[MXN];

void calc() {
    pow_2[0] = 1;
    for(int i = 1; i < MXN; i++) {
        pow_2[i] = (pow_2[i - 1] * 2) % mod; 
    }
}

int solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0, d = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'B') {
            if(d < k) { 
                d++; continue; 
            }
            ans = (ans + pow_2[i + 1]) % mod;
        }
        d = max(d - 1, 0);
    }
    return ans;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    calc();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        printf("Case #%d: %d\n", cs, solve());
    }
    return 0;
}