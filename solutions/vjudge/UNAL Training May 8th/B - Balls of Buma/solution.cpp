#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 3e5 + 5;
int a[MXN];
char c[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int it = 0, lst = 0;
    c[0] = s[0];
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == s[lst])a[it]++;
        else a[++it] = 1, c[it] = s[i];
        lst = i;
    }
    it++;
    if((it & 1) && a[it/2] >= 2) {
        bool ok = 1;
        for(int l = 0, r = it - 1; l < it/2; l++, r--) {
            ok &= (a[l] + a[r] >= 3) && (c[l] == c[r]);
        } 
        if(ok) {
            cout << a[it/2] + 1 << endl; 
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}