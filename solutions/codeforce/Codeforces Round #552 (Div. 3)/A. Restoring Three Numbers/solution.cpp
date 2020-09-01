#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x[4];
    for(int i = 0; i < 4; i++) {
        cin >> x[i];
    }
    sort(x, x + 4);
    int a, b, c;
    do {
        a = x[3] - x[2], b = x[3] - x[1], c = x[3] - x[0];
        if(a + b == x[0] && a + c == x[1] && b + c == x[2] && a + b + c == x[3])
            break;
    } while(next_permutation(x, x + 4));
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}