#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int top = 0;
    for(int i = 0; i < n; i++) {
        top += s[i] == '(';
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            if(top < n / 2) s[i] = '(', top++;
            else s[i] = ')';
        }
        if(s[i] == '(') sum++;
        if(s[i] == ')') sum--;
        if((i != n - 1 && sum <= 0) || (i == n - 1 && (s[i] == '(' || sum != 0))) {
            cout << ":(" << endl;
            return 0;
        }
    }
    cout << s << endl;
    return 0;
}