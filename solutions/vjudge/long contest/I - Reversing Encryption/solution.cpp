#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; string s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            reverse(s.begin(), s.begin() + i);
        }
    }
    cout << s << endl;
    return 0;
}