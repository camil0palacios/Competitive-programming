#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        string t, s;
        cin >> t;
        int ones = 0, zeros = 0;
        for(int i = 0; i < t.size(); i++) {
            ones += t[i] == '1';
            zeros += t[i] == '0';
        }
        int cur = t[0] == '1' ? 1 : 0;
        for(int i = 0; i < 2 * t.size(); i++) {
            s += cur ? '1' : '0';
            if(ones && zeros)cur ^= 1;
        }
        cout << s << endl;
    }
    return 0;
}