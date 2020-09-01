#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int get(string s) {
    reverse(s.begin(), s.end());
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') num |= (1 << i);
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        string s1, s2;
        cin >> s1 >> s2;
        int a = get(s1), b = get(s2);
        cout << "Pair #" << cs << ": ";
        if(gcd(a, b) != 1) cout << "All you need is love!" << endl;
        else cout << "Love is not all you need!" << endl;
    }
    return 0;
}