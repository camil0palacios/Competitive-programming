#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, c, a, b;
    cin >> n >> c >> a;
    int words = 1;
    for(int i = 1; i < n; i++) {
        cin >> b;
        if(b - a > c)words = 1;
        else words++;
        a = b;
    }
    cout << words << endl;
    return 0;
}