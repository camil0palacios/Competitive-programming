#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x); m[x]++;
        }
        int x = 0;
        for(auto & i : m) {
            if(s.size() - 1 >= i.second) {
                x = max(x, i.second);
            } else {
                x = max(x, (int) s.size() - 1);
            }
            if(s.size() >= i.second - 1) {
                x = max(x, i.second - 1);
            } else {
                x = max(x, (int) s.size());
            }
        }
        cout << x << endl;
    }
    return 0;
}