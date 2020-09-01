#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, g, b;
        cin >> n >> g >> b;
        long long mid = (n + 1) / 2;
        long long ans = max(mid + b * ((mid - 1)/g), n);
        cout << ans << endl;
    }
    return 0;
}