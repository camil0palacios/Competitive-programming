#include <bits/stdc++.h>
#define endl '\n'
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fori(i, a, b) for(int i = a; i < b; i++)
#define forr(i, a) for(int i = a; i >= 0; i--)
#define all(v) v.begin(), v.end()
using namespace std;

int main() {
    io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s, t;
        cin >> n >> s;
        int z = 0;
        string stk;
        forr(i, n - 1) {
            if(s[i] == '1') {
                bool ok = 0;
                while(!stk.empty() && z > 1 && stk.back() == '0') {
                    stk.pop_back();
                    ok = 1;
                    z--;
                } 
                if(stk.empty() || (stk.size() && stk.back() == '1')) stk += s[i];
            } else {
                stk += s[i];
                z++;
            }
        }
        reverse(all(stk));
        cout << stk << endl;
    }
    return 0;
}