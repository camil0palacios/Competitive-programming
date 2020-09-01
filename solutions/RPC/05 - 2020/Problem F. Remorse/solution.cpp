#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ll f[26];
priority_queue<ll, vector<ll>, greater<ll>> q;

void cal() {
    for(int len = 1; len <= 6; len++) {
        for(int j = 0; j < (1 << len); j++) {
            int p = 0, d = 0;
            for(int k = 0; k < len; k++) { 
                int x = (j >> k) & 1;
                p += x == 0, d += x == 1;
            }
            q.push(p + d*3 + (len - 1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cal();
    string s, t;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(!isalpha(s[i])) continue;
        char c = tolower(s[i]);
        t += c;
        f[c - 'a']++;
    }
    sort(f, f + 26, greater<ll>());
    long long ans = 0;
    for(int i = 0; i < 26; i++) {
        if(f[i]) {
            ans += 1LL*f[i]*q.top();
            q.pop();
        }
    }
    ans += 3LL*(t.size() - 1);
    cout << ans << endl;
    return 0;
}