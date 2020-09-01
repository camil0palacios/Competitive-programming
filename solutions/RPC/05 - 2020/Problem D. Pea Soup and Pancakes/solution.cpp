#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string ans;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        cin.ignore();
        string s, t;
        getline(cin, s);
        set<string> m;
        for(int j = 0; j < k; j++) {
            getline(cin, t);
            m.insert(t);
        }
        if(m.count("pea soup") && m.count("pancakes") && ans.empty()) {
            ans = s;
        }
    }
    cout << (ans == "" ? "Anywhere is fine I guess" : ans) << endl;
    return 0;
}
