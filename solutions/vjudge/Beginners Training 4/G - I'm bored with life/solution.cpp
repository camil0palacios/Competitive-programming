#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int mn = min(a, b);
    int f = 1;
    for(int i = 1; i <= mn; i++) {
        f = f * i;
    }
    cout << f << endl;
    return 0;
}