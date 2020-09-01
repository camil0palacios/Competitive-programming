#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string preffix(string & s) {
    string t;
    for(int i = 0; i < s.size() && s[i] != '*'; i++){
        t += s[i];
    } 
    return t;
}

string suffix(string & s) {
    string t;
    for(int i = s.size() - 1; i >= 0 && s[i] != '*'; i--) {
        t += s[i];
    }
    reverse(t.begin(), t.end());
    return t;
}

void sol() {
    int n;
    cin >> n;
    string a[n], pre[n], suf[n];
    int lp = 0, ls = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = preffix(a[i]);
        suf[i] = suffix(a[i]);
        if(pre[lp].size() < pre[i].size()) lp = i;
        if(suf[ls].size() < suf[i].size()) ls = i;
    }
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        if(pre[lp].substr(0, pre[i].size()) != pre[i]) ok = 0;
        if(suf[ls].substr(suf[ls].size() - suf[i].size()) != suf[i]) ok = 0;
    }
    if(ok) {
        string ans = pre[lp];
        for(int i = 0; i < n; i++) {
            for(int j = pre[i].size(); j < a[i].size() - suf[i].size(); j++) {
                if(a[i][j] != '*') ans += a[i][j];
            }
        }
        ans += suf[ls];
        cout << ans << endl;
    } else {
        cout << '*' << endl;
    }
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