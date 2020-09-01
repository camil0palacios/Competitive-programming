#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int one = 0, ans = 0;
    for(int i = 0; i < s.size(); i++) {
        one += s[i] == '1';
        ans += i % 2 == 0;
    }
    if(s.size() & 1 && one == 1) ans--;
    if(s.size() == 1 && s[0] == '0') ans = 0;
    cout << ans << endl;
    return 0;
}