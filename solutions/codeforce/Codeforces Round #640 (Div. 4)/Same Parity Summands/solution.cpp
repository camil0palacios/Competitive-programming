#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        if(n < k) cout << "NO" << endl; 
        else {
            int a = 0, b = 0;
            vector<int> ans1, ans2;
            for(int i = 0; i < k - 1; i++) {
                a += 1;
                b += 2;
                ans1.emplace_back(1);
                ans2.emplace_back(2);
            }
            int c = n - a, d = n - b;
            if(c % 2 == 1 && c > 0) {
                ans1.emplace_back(c);
                cout << "YES" << endl;
                for(auto & x : ans1) {
                    cout << x << ' ';
                }
                cout << endl;
            }
            else if(d % 2 == 0 && d > 0) {
                ans2.emplace_back(d);
                cout << "YES" << endl;
                for(auto & x : ans2) {
                    cout << x << ' ';
                }
                cout << endl;
            } 
            else {
                cout << "NO" << endl;
            }
        }
    }
}