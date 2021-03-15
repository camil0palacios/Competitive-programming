#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll nC2 = ((ll)i*i*((ll)i*i - 1)) / 2;
        ll att = 4LL*(i - 1)*(i - 2);
        cout << nC2 - att << endl;
    }
    return 0;
}