#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int c;
    cin >> c;
    int ans = 100, cur = 100;
    for(int i = 0; i < c; i++) {
        int x; cin >> x;
        cur += x;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}