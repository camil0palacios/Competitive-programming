#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string rec(vector<int> & a, string & s, int i, int j) {
    int x = i;
    string ans;
    for(int k = i; k <= j; k++) {
        if(a[k] <= 0) {
            for(int y = x; y <= k; y++) a[y]--;
            if(x < k) ans += string("(" + rec(a, s, x, k) + ")");
            a[k]++;
            if(a[k] == 0)
                ans += s[k];
            x = k + 1;
        }
    }
    return ans;
}

void sol() {
    string s;
    cin >> s;
    s += "0";
    vector<int> a(s.size());
    for(int i = 0; i < s.size(); i++) {
        a[i] = s[i] - '0';
    }
    string ans = rec(a, s, 0, a.size() - 1);
    for(int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        sol();
    }
    return 0;
}