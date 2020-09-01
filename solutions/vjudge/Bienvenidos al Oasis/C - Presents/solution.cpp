#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a[101];
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x-1] = i; 
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}