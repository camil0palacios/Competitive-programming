#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char a[25][25];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        int cnt[2] = {0 , 0};
        for(int j = 0; j < n; j++) {
            int idx = a[i][j] == 'W';
            cnt[idx]++;
        }
        ok &= cnt[0] == cnt[1];
    }
    for(int j = 0; j < n; j++) {
        int cnt[2] = {0 , 0};
        for(int i = 0; i < n; i++) {
            int idx = a[i][j] == 'W';
            cnt[idx]++;
        }
        ok &= cnt[0] == cnt[1];
    }
    for(int i = 2; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ok &= !(a[i][j] == a[i - 1][j] && a[i - 1][j] == a[i - 2][j]);
        }
    }
    for(int j = 2; j < n; j++) {
        for(int i = 0; i < n; i++) {
            ok &= !(a[i][j] == a[i][j - 1] && a[i][j - 1] == a[i][j - 2]);
        }
    }
    cout << ok << endl;
    return 0;
}