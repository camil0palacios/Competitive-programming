#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void check(vector<int> & cnt, int x) {
    while(x) {
        int dig = x % 10;
        cnt[dig]++;
        x /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    while(cin >> a >> b && (a || b)) {
        vector<int> cnt(10);
        for(int i = a; i <= b; i++) {
            check(cnt, i);
        }
        for(int i = 0; i < 10; i++) {
            cout << cnt[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}