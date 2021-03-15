#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(b < a) swap(a, b);
        cout << (b - a + 10 - 1) / 10 << endl;
    }
    return 0;
}