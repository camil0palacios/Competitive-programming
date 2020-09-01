#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        long long sum = 0, xr = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            sum += x;
            xr ^= x;
        }
        cout << 2 << endl;
        cout << xr << ' ' << xr + sum << endl;
    }
    return 0;
}