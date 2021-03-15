#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 101;
int a[MXN], b[MXN], l[MXN];

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
        int m = 0;
        for(int i = 0; i < n; i++) {
            cin >> l[i];
            if(!l[i]) b[m++] = a[i];
        }
        sort(b, b + m);
        reverse(b, b + m);
        for(int i = 0, j = 0; i < n; i++) {
            if(!l[i]) a[i] = b[j++];
        } 
        for(int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        int p = 0;
        for(int i = 0; i < n; i++) {
            p += a[i];
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}