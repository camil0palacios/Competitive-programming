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
        long long sum = 0;
        for(int i = 1; i*i <= n; i++) {
            if(n % i == 0) {
                sum += i;
                if(n / i != i &&  n / i != n) {
                    sum += n / i;
                }
            }
        }
        if(sum < n) cout << "deficient";
        else if(sum == n) cout << "perfect";
        else cout << "abundant";
        cout << endl;
    }
    return 0;
}