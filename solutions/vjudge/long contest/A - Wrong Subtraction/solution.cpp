#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int r = n % 10;
        if(r == 0) n /= 10;
        else n--;
    }
    cout << n << endl;
    return 0;
}