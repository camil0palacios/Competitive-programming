#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN], b[MXN], vis[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(i && a[i - 1] < a[i]) b[i] = a[i - 1];
        else {
            while(vis[j]) j++;
            b[i] = j++;
        }
        if(i) cout << ' ';
        cout << b[i];
    }
    cout << endl;
    return 0;
}