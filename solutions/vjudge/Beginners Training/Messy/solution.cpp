#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k; string s;
        cin >> n >> k >> s;
        string t(n, '?');
        for(int i = 0; i < 2*(k - 1); i += 2) t[i] = '(', t[i + 1] = ')';
        for(int i = 0; i < n/2 - (k - 1); i++) t[2*(k - 1) + i] = '(', t[n - i - 1] = ')'; 
        vector<pair<int,int>> ans;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) continue;
            int j = i;
            while(j < n && s[j] != t[i]){ j++; } 
            ans.emplace_back(i + 1, j + 1);
            reverse(s.begin() + i, s.begin() + j + 1);
        }
        cout << ans.size() << endl;
        for(auto & p: ans) {
            cout << p.first << ' ' << p.second << endl;
        }
    }
    return 0;
}