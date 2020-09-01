#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> f(26);
    for(int i = 0; i < s.size(); i++) {
        f[s[i] - 'a']++;
    }
    sort(s.begin(), s.end(), [&](const char & a, const char & b) {
        if(f[a - 'a'] == f[b - 'a'])return a < b;
        return f[a - 'a'] > f[b - 'a'];
    });
    cout << s << endl;
    return 0;
}