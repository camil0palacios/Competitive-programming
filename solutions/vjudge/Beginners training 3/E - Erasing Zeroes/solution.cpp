#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i, j;
        for(i = 0; i < s.size() && s[i] == '0'; i++) {}
        for(j = s.size() - 1; j >= 0 && s[j] == '0'; j--) {}
        int ans = 0;
        for(; i <= j; i++) {
            ans += s[i] == '0';
        }
        cout << ans << endl;
    }
    return 0;
}