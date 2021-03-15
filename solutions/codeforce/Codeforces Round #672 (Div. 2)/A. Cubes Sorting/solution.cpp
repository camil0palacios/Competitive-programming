#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int MXN = 50000;
int a[MXN];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool ok = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] <= a[i + 1]) ok = 1;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}