#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ev, od;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) od.emplace_back(a[i]);
            else ev.emplace_back(a[i]);
        }
        if(od.size() % 2 == 0 && ev.size() % 2 == 0) {
            cout << "YES" << endl;
        } else {
            bool ok = 0;
            for(int i = 0; i < ev.size(); i++) {
                for(int j = 0; j < od.size(); j++) {
                    if(abs(ev[i] - od[j]) == 1) ok = 1;
                }
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
    return 0;
}