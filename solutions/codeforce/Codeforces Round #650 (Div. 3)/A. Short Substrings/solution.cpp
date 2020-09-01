#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s; 
        cin >> s;
        for(int i = 0; i < s.size(); i += 2) {
            cout << s[i];
        }
        cout << s[s.size() - 1];
        cout << endl;
    }
    return 0;
}