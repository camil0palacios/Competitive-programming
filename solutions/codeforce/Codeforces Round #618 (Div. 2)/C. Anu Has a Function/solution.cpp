#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int idx = 0, cnt = 0;
    for(int i = 30; i >= 0; i--) {
        cnt = 0;
        for(int j = 0; j < n; j++) {
            if((a[j] >> i) & 1) cnt++, idx = j;
        }
        if(cnt == 1) break;
    }
    swap(a[idx], a[0]);
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}