#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int a = 0, b = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                if(s[i] == '1') a++;
                else b++;
            }
        } 
        cout << max(a, b) << endl;
    }
    return 0;
}