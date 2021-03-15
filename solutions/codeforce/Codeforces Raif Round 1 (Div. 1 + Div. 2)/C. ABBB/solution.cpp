#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s, ans;
        cin >> s;
        int n = (int) s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B' && ans.size()) ans.pop_back();
            else ans += s[i];
        }
        cout << ans.size() << endl;
    }
    return 0;
}