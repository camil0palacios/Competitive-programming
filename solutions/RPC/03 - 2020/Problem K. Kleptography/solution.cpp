#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    string tmp, b;
    cin >> n >> m >> tmp >> b;
    string a;
    for(int i = 0; i < m - n; i++) {
        a += '?';
    }
    for(int i = 0; i < n; i++) {
        a += tmp[i];
    }
    for(int i = m - n - 1; i >= 0; i--) {
        a[i] = char(((b[i + n] - 'a') - (a[i + n] - 'a') + 26) % 26 + 'a');
    }
    cout << a << endl;
    return 0;
}