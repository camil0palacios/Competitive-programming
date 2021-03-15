#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int sum(int a) {
    int s = 0;
    while(a) { s += a % 10, a /= 10; }
    return s;
}

int check(int a, int b) {
    int sa = sum(a), sb = sum(b);
    if(sa == sb) return min(a, b);
    return sa < sb ? b : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            ans = check(ans, i);
            if(n / i != i) ans = check(ans, n / i);
        }
    }
    cout << ans << endl;
    return 0;   
}