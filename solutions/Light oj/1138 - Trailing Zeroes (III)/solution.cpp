#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int sum(int x) {
    int s = 0;
    while(x) {
        s += x / 5;
        x /= 5;
    }
    return s; 
}

void sol() {
    int q;
    cin >> q;
    int l = 0, r = 1e9;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        int s = sum(mid);
        if(s == q){
            ans = mid;
            r = mid - 1;
        }
        else if(s < q)l = mid + 1;
        else r = mid - 1;
    }
    if(!ans)cout << "impossible" << endl;
    else cout << ans << endl;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ": ";
        sol();
    }
    return 0;
}