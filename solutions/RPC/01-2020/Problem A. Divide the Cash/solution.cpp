#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    int sum = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    d /= sum;
    for(int i = 0; i < n; i++) {
        cout << a[i] * d << endl;
    }
    return 0;
}