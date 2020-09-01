#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    int mx = 0, idx = 0;
    for(int i = 0; i < n - 1; i++) {
        int cnt = 0;
        for(int j = 0; j < n - 1; j++) {
            if(s[i] == s[j] && s[i + 1] == s[j + 1]) {
                cnt++;
            }
        }
        if(mx < cnt) {
            mx = cnt;
            idx = i;
        }
    }
    cout << s[idx] << s[idx + 1] << endl;
    return 0;
}