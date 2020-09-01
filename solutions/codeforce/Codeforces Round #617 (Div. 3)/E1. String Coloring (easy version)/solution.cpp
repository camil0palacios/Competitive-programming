#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    char l1 = 'a', l2 = 'a';
    string t;
    for(int i = 0; i < n; i++) {
        if(s[i] >= l1) {
            t += '0';
            l1 = s[i];
        }
        else if(s[i] >= l2) {
            t += '1';
            l2 = s[i];
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << t << endl;
    return 0;
}