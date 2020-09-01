#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0, k = 0;
        while(true) {
            sum += (1 << k);
            k++;
            if(n % sum == 0 && k != 1) break;
        }
        cout << n / sum << endl;
    }
    return 0;
}