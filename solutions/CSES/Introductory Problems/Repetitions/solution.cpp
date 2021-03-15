#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp = 0, j = i;
        while(j < n && s[i] == s[j]) j++;
        ans = max(ans, j - i);
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}