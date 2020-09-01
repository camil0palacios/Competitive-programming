#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    cout << max(min((k + 1)/ 2 - 1, n - k/2), 0LL) << endl;
    return 0;
}