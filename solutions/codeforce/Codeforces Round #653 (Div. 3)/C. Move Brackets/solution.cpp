#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += s[i] == '(' ? 1 : -1;
            ans = min(ans, cnt);
        }
        cout << abs(ans) << endl;
    }
    
    return 0;
}