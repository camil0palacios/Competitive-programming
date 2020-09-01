// #include <bits/stdc++.h>
// #define endl '\n'
using namespace std;
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define sz(v) (int) v.size()

typedef pair<int,int> ii;

const int inf = 1e9;
int dp[31][12];
ii opt[31][12];
int frq[30];

int Dp(int i, int k) {
    if(i == 30) return k == 0 ? 0 : inf;
    if(dp[i][k] != -1) return dp[i][k];
    int ans = inf, c = 0;
    for(int j = i + 1; j <= 30; j++) {
        c += frq[j - 1] * (j - i);
        int tmp = (k ? Dp(j, k - 1) + c : inf);
        if(tmp < ans) {
            ans = tmp;
            opt[i][k].first = j; 
            opt[i][k].second = k - 1;
        }
    }
    return dp[i][k] = ans;
}

int get(char c) {
    if(isalpha(c)) return c - 'a';
    if(c == '+') return 26;
    if(c == '*') return 27;
    if(c == '/') return 28;
    else return 29;
}

char idx[30] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '+', '*', '/', '?' };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        // dp[i][k] = max(dp[j][k - 1] + cost(i, j));
        int m; cin >> m;
        memset(frq, 0, sizeof frq);
        for(int i = 0; i < m; i++){ 
            string s; cin >> s;
            for(int i = 0; i < sz(s); i++) {
                frq[get(s[i])]++;
            }
        }
        memset(dp, -1, sizeof dp);
        Dp(0, 12);
        int a = 0, b = 12;
        for(int i = 0; i < 11; i++) {
            cout << idx[opt[a][b].first];
            int x = opt[a][b].first;
            int y = opt[a][b].second;
            a = x, b = y;
        }
        cout << endl;
    }
    return 0;
}