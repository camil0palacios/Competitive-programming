#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
int a[MXN], bit[22];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 20; j++) {
            if((a[i] >> j) & 1) 
                bit[j]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long num = 0;
        for(int j = 0; j < 20; j++) {
            if(bit[j]) {
                num += (1 << j);
                bit[j]--;
            }
        }
        ans += num * num;
    }
    cout << ans << endl;
    return 0;
}