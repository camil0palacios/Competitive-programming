#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];  
        }
        int ok = 0;
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j > i + 1; j--) {
                if(a[i] == a[j])ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}