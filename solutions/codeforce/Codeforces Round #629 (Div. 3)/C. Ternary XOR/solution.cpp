#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >>  t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        string a(n, '1'), b(n, '1');
        bool mx = 0;
        for(int i = 1; i < n; i++) {
            char x, y;
            if(mx) {
                a[i] = '0';
                b[i] = s[i];
            } else {
                if(s[i] == '1'){
                    a[i] = '1', b[i] = '0';
                    mx = 1;
                }
                else if(s[i] == '2'){
                    a[i] = '1', b[i] = '1';
                }
                else a[i] = '0', b[i] = '0';
            }
        }
        cout << a << endl;
        cout << b << endl;
    }
    return 0;
}