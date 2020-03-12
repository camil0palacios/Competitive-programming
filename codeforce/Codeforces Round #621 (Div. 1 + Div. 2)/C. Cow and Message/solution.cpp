#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long a[26][26];
long long b[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++){
        int x = s[i] - 'a';
        for(int j = 0; j < 26; j++){
            a[j][x] += b[j];
        }
        b[x]++;
    }
    long long mx = 0;
    for(int i = 0; i < 26; i++){
        mx = max(mx, b[i]);
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            mx = max(mx, a[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}