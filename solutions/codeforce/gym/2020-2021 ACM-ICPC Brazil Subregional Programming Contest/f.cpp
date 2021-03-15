#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    bool cur = 0;
    int p1 = 0, p2 = 0, g1 = 0, g2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'Q') {
            string ans;
            if(i != n - 1) {
                ans = to_string(g1) + " (" + to_string(p1);
                if(!cur) ans += "*";
                ans += ") - " + to_string(g2) + " (" + to_string(p2);
                if(cur) ans += "*";
                ans += ")";
            } else {
                if(g1 > g2) ans = to_string(g1) + " (winner) - " + to_string(g2);
                else ans = to_string(g1) + " - " + to_string(g2) + " (winner)";
            }
            cout << ans << endl;
        } else {
            if(s[i] == 'R') {
                cur ^= 1;
            }
            (cur ? p2++ : p1++);
            int d = abs(p1 - p2);
            bool ok = 0;
            if((p1 > p2 && d >= 2 && p1 >= 5) || p1 == 10) ok = 1, g1++;
            if((p2 > p1 && d >= 2 && p2 >= 5) || p2 == 10) ok = 1, g2++;
            if(ok) p1 = p2 = 0;
        }
    }
    return 0;
}