#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e6 + 5;
int cnt[MXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 1; j * j <= x; j++) {
            if(x % j == 0) {
                cnt[j]++;
                if(x / j != j) cnt[x / j]++;
            }
        } 
    }
    int lst = 1;
    for(int i = 1; i < MXN; i++) {
        if(cnt[i] >= 2) {
            lst = i;
        }
    }
    cout << lst << endl;
    return 0;
}