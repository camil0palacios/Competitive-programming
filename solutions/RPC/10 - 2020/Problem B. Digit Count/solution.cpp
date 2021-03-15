#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int check(int n, int dig) {
    int ans = 0;
    while(n) {
        ans += (n % 10 == dig);
        n /= 10;
    }
    return ans;
}

int count(int n, int dig) {
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += check(i, dig);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r, dig;
    cin >> l >> r >> dig;
    int a = count(l - 1, dig), b = count(r, dig);
    cout << b - a << endl;   
    return 0;
}