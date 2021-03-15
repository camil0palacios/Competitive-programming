#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x;
    cin >> x;
    vector<int> ans;
    int op = 1;
    for(; op <= 40; op++) {
        int lst = 0;
        for(int i = 0; (x >> i); i++) {
            if((x >> i) & 1) lst = i;
        }
        if((1 << (lst + 1)) - 1 == x) break;
        if(op & 1) {
            int n = 0;
            for(int i = 0; (x >> i); i++) {
                if(!((x >> i) & 1)) n = i;
            }   
            x ^= (1 << (n + 1)) - 1;
            ans.emplace_back(n + 1);
        } else {
            x += 1;
        }
    }
    op--;
    cout << op << endl;
    op = (op + 1) / 2;
    if(op) {
        for(int i = 0; i < op; i++) {
            cout << ans[i] << ' ';
        } 
        cout << endl;
    }
    return 0;
}