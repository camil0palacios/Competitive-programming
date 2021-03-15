#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> pos, neg;
        int spos = 0, sneg = 0;
        int z = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > 0) {
                pos.emplace_back(a[i]);
                spos += a[i];
            }
            if(a[i] < 0) {
                neg.emplace_back(a[i]);
                sneg += a[i];
            }
            if(a[i] == 0) z++;
        }
        if(spos != -sneg) {
            cout << "YES" << endl;
            if(spos > -sneg) {
                for(auto & i : pos) cout << i << ' ';
                for(auto & i : neg) cout << i << ' ';  
            } else {
                for(auto & i : neg) cout << i << ' ';
                for(auto & i : pos) cout << i << ' ';
            }
            for(int i = 0; i < z; i++) {
                cout << 0 << ' ';
            }
            cout << endl;
        } 
        else cout << "NO" << endl;
    }
    return 0; 
}