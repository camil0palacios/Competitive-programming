#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int s = 0;
        for(int j = i; j < n; j++) {
            s ^= a[j];
            mx = max(mx, s);
        }
    }
    cout << mx << endl;
    return 0;
}