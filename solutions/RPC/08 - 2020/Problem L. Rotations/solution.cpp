#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        string num;
        for(int i = 0; i < 32; i++) {
            bool bit = (n >> i) & 1;
            num += char(bit + '0');
        }
        num += num;
        vector<bool> check(64);
        for(int i = 0; i < num.size() - 5; i++) {
            int tmp = 0;
            for(int j = 0; j < 5; j++) {
                tmp |= (num[i + j] - '0') << j;
            }
            check[tmp] = 1;
        }
        bool ok = 1;
        for(int i = 0; i < 32; i++) {
            ok &= check[i];
        }
        cout << (ok ? "yes" : "no") << endl;
    }
    return 0;
}