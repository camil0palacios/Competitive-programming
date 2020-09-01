#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        while(n) {
            if(n == 3) {
                s += '7';
                n -= 3;
            }
            else if(n >= 2){
                s += '1';
                n -= 2;
            } 
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}