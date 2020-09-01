#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v;
    cin >> v;
    int ans = 1e9;
    for(int i = 1; i * i <= v; i++) {
        for(int j = 1; j * j <= v; j++) {
            int k = v / (i * j);
            if(i*j*k == v){
                ans = min(ans, 2*i*j + 2*i*k + 2*j*k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}