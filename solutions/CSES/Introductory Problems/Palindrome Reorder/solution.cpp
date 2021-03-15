#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int frq[26];
    memset(frq, 0, sizeof frq);
    for(int i = 0; i < s.size(); i++) {
        frq[s[i] - 'A']++;
    }
    int can = 0;
    for(int i = 0; i < 26; i++) {
        can += frq[i] & 1;
    }
    if(can < 2) {
        string a, b, c;
        for(int i = 0; i < 26; i++) {
            if(frq[i] & 1) c = string(frq[i], char(i + 'A'));
            else if(frq[i]) a += string(frq[i] / 2, char(i + 'A'));
        }
        b = a;
        if(b.size()) reverse(b.begin(), b.end());
        cout << a << c << b << endl;
    } else {
        cout << "NO SOLUTION" << endl;    
    }
    return 0;
}