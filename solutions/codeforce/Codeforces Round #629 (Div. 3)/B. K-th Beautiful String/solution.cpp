#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        long long p2 = 2;
        int i = n - 2, acc = 0;
        for(; i >= 0; i--) {
            if(n - 1 - i + acc >= k) {
                break;
            }
            acc += n - 1 - i;
        }
        string s(n, 'a');
        int nk = n - 1 - i + acc - k;
        s[i] = s[i + 1 + nk] = 'b';
        cout << s << endl;
    }
    return 0;
}