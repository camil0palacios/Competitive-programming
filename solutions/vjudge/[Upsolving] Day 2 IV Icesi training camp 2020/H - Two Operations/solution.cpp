#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int f[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, t;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        f[s[i] - 'a']++;
    }
    for(int i = 0; i < 25; i++) {
        f[i + 1] += f[i] / 2;
        f[i] = f[i] % 2;
    }
    for(int i = 25; i >= 0; i--) {
        if(f[i])
            cout << string(f[i], char(i + 'a'));
    }
    cout << endl;
    return 0;
}