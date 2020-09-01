#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> p(n);
        for(int i = 0; i < m; i++){
            int pos;
            cin >> pos;
            p[pos - 1] = 1;
        }
        while(true){
            bool ok = 0;
            for(int i = 0; i < n - 1; i++){
                if(p[i] && a[i] > a[i + 1]){
                    ok = 1;
                    swap(a[i], a[i + 1]);
                }
            }
            if(!ok)break;
        }
        bool ok = 1;
        for(int i = 0; i < n - 1; i++){
            ok &= a[i] <= a[i + 1];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}