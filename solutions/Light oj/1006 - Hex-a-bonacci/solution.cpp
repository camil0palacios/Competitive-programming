#include <bits/stdc++.h>
using namespace std;

long long fn[10005];
long long mod = 10000007;

void solve(){
    int n;
    for(int i = 0; i < 6; i++){
        cin >> fn[i];
    }
    cin >> n;
    for(int i = 6; i <= n; i++){
        fn[i] = fn[i-1] + fn[i-2] + fn[i-3] + fn[i-4] + fn[i-5] + fn[i-6];
        fn[i] = fn[i] % mod;
    }
    cout << fn[n] % mod << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}