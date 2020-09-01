#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, x;
    cin >> a >> b >> x;
    string s; bool bit = (a > b ? 0 : 1);
    for(int i = 0; i < x; i++) {
        s += (bit ? '1' : '0');
        a -= !bit; b -= bit;
        bit ^= 1;
    }
    bit ^= 1;
    if(bit) s += string(b, '1') + string(a, '0');
    else s += string(a, '0') + string(b, '1');
    cout << s << endl;
    return 0;
}