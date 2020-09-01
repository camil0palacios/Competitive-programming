#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        l += s[i] == 'L';
        r += s[i] == 'R';
    }
    cout << l + r + 1 << endl;
    return 0;
}