#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, [&](const string & s, const string & t){
        return s.size() != t.size() ? s.size() < t.size() : s < t;
    });
    bool ok = 1;
    for(int i = 1; i < n; i++) {
        bool tmp = 0;
        for(int j = 0; j <= a[i].size() - a[i - 1].size(); j++) {
            // cout << a[i].substr(j, a[i - 1].size()) << ' ' << a[i - 1] << endl;
            if(a[i].substr(j, a[i - 1].size()) == a[i - 1]){
                tmp = 1;
            }
        }
        ok &= tmp;
    }
    if(ok) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}