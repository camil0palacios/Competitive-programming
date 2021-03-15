#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a, b;
    ll sa = 0, sb = 0;
    for(int i = n; i >= 1; i--) {
        if(sa <= sb) {
            a.emplace_back(i);
            sa += i;
        } else {
            b.emplace_back(i);
            sb += i;
        }
    }
    if(sa == sb) {
        cout << "YES" << endl;
        cout << a.size() << endl;
        for(auto & i : a) {
            cout << i << ' ';
        }
        cout << endl;
        cout << b.size() << endl;
        for(auto & i : b) {
            cout << i << ' ';
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}