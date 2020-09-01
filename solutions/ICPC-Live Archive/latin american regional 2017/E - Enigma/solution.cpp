#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s, t;
int n;
int dp[1010][1010];

int dptop(int idx, int res) {
    if(idx == s.size()) return res == 0;
    if(dp[idx][res] != -1) return dp[idx][res];
    int ans = 0;
    if(s[idx] == '?') {
        for(int i = idx ? 0 : 1; i <= 9; i++) {
            ans |= dptop(idx + 1, (res * 10 + i) % n);
            if(ans) {
                t[idx] = char(i + '0');     
                break;
            }
        }
    } else {
        ans |= dptop(idx + 1, (res * 10 + (s[idx] - '0')) % n);
        if(ans) t[idx] = s[idx];
    }
    return dp[idx][res] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> s >> n) {
        t = string(s.size(), '?');
        memset(dp, -1, sizeof dp);
        if(dptop(0, 0)) {
            cout << t << endl;  
        } else {
            cout << "*" << endl;
        }
    }
    return 0;
}