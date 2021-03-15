#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for(int & i : a) cin >> i;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != i + 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}