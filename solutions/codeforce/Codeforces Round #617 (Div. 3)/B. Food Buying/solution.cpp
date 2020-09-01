#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int spend = 0;
        int pw = 1e9;
        while(n) {
            while(n < pw) pw /= 10;
            spend += pw;
            n -= pw - pw / 10;
        } 
        cout << spend << endl;
    }
    return 0;
}