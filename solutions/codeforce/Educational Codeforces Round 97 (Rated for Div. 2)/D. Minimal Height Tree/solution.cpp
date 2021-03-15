#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int depth = 0;
        int child = 0, prev = 1, cur = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i - 1]) {
                child++;
                continue;
            }
            cur++;
            if(cur == prev) {
                prev = child;
                child = 1;
                cur = 0;
                depth++;
            } else {
                child++;
            }
        }
        cout << depth + 1 << endl;
    }
    return 0;
}