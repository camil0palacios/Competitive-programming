#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(), a.end()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin >> k >> n) {
        int f[k + 1];
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            f[x]++;
        }
        set<int> s;
        vector<pair<int,int>> v;
        for(int i = 1; i <= k; i++) {
            v.emplace_back(f[i], i);
            s.insert(f[i]);
        }
        if(s.size() > 3) {
            cout << "*" << endl;
        } else {
            sort(all(v));
            // int mn = *s.begin(), mx = *s.rbegin();
            bool ok = 1;
            v[0].first++;
            for(int i = 1; i < k; i++) {
                ok &= v[i].first == v[i - 1].first;
            }
            v[0].first--;
            if(ok) {
                cout << "+" << v[0].second << endl;
                continue;
            }
            ok = 1;
            v[v.size() - 1].first--;
            for(int i = 1; i < k; i++) {
                ok &= v[i].first == v[i - 1].first;
            }
            v[v.size() - 1].first++;
            if(ok) {
                cout << "-" << v[v.size() - 1].second << endl;
                continue;
            }
            ok = 1;
            v[0].first++;
            v[v.size() - 1].first--;
            for(int i = 1; i < k; i++) {
                ok &= v[i].first == v[i - 1].first;
            }
            if(ok) cout <<  "-" << v[v.size() - 1].second << " +" << v[0].second << endl;
            else cout << "*" << endl;
        }
    }
    return 0;
}