#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int sol(int x, int y) {
    return x == y ? 2 : x < y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;
    char res[4] = { '+' , '-', '0', '?' };
    cout << res[sol(x + z, y) == sol(x, y + z) ? sol(x, y) : 3];
    return 0;
}