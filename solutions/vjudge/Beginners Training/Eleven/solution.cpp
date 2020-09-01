#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long f[n + 1]; f[0] = f[1] = 1;
    unordered_set<long long> s;
    s.insert(1);
    for(int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        s.insert(f[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(s.count(i)) cout << 'O';
        else cout << 'o';
    }
    cout << endl;
    return 0;
}