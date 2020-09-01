#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 110;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mn = 1e9;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += abs(a[i] - a[j]) & 1;
        }
        mn = min(mn, sum);
    }
    cout << mn << endl;
    return 0;
}