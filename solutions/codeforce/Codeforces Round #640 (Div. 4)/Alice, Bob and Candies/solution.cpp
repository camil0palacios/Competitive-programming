#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> alice, bob;
        int x = 0, y = 0, turn = 0;
        int l = 0, r = n - 1, cnt = 0, prv = 0;
        while(l <= r) {
            int nmove = 0;
            while(!turn && l <= r && nmove <= prv){
                x += a[l];
                nmove += a[l];
                l++;
            }
            while(turn && r >= l && nmove <= prv) {
                y += a[r];
                nmove += a[r];
                r--;
            }
            prv = nmove;
            cnt++;
            turn ^= 1;
        }
        cout << cnt << ' ' << x << ' ' << y << endl;
    }
    return 0;
}