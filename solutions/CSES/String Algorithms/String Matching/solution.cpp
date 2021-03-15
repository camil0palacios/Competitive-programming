#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e6 + 5;
int p[MXN];

void build(string & s) {
    int n = s.size(), j = 0;
    for(int i = 1; i < n; i++) {
        while(j != 0 && s[i] != s[j]) j = p[j - 1];   
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
}

int kmp(string & s, string & t) {
    int n = s.size(), m = t.size();
    int j = 0, match = 0;
    for(int i = 0; i < n; i++) {
        while(j != 0 && s[i] != t[j]) j = p[j - 1];
        if(s[i] == t[j]) j++;
        if(j == m) match++, j = p[j - 1];
    }
    return match;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    build(t);
    cout << kmp(s, t) << endl;
    return 0;
}