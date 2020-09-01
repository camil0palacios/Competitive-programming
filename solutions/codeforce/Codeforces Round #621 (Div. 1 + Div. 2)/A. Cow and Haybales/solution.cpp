#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = a[0];
        for(int i = 1; i < n; i++){ 
            int x = min(d / i, a[i]);
            ans += x;
            d -= x * i;
            
        }
        cout << ans << endl;
    }
    return 0;
}