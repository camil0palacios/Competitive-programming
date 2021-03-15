#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    int k = 0;
    for(int i = 1; i < n; i += 2) {
        b[i] = a[k++];
    }
    for(int i = 0; i < n; i += 2) {
        b[i] = a[k++];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(b[i - 1] > b[i] && b[i + 1] > b[i]) 
            ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}