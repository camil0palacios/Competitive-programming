#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    string t(n, '?');
    int l = n / 2 - 1, r = n / 2;
    if(n & 1) t[n / 2] = s[0], r++;
    bool nxt = 0;
    for(int i = n & 1; i < n; i++) {
        if(!nxt) t[l--] = s[i];
        else t[r++] = s[i];
        nxt ^= 1;
    }
    cout << t << endl;
    return 0;
}