#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool check(int d, string & s) {
    bool ok = 1;
    int i = 0, n = s.size();
    while(ok) {
        ok = 0;
        int tmp = min(n, i - 1 + d);
        for(int j = i; j <= tmp; j++) {
            if(j == n)return 1;
            if(s[j] == 'R') {
                ok = 1, i = j + 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int l = 0, r = s.size() + 2;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(check(mid, s))r = mid;
            else l = mid;
        }
        cout << r << endl;
    }
    return 0;
}