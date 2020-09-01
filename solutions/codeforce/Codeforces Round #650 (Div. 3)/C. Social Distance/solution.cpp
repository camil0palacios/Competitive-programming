#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
char a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> pos;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == '1') pos.emplace_back(i);
        }
        int ans = 0;
        if(pos.size()) {
            for(int i = 1; i < pos.size(); i++) {
                int j = pos[i - 1] + k + 1; 
                while(pos[i - 1] + k < j && j < pos[i] - k) {
                    j += k + 1;
                    ans++;
                }
            }
            int j = 0;
            while(j < pos[0] - k) ans++, j += k + 1;
            j = pos[pos.size() - 1] + k + 1;
            while(j < n) ans++, j += k + 1;
        } else {
            for(int i = 0; i < n; i += k + 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}