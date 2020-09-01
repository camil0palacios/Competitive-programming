#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


bool pr(int num) {
    if(num == 2) return 1;
    if(num < 2 || num % 2 == 0) return 0;
    for(int i = 3; i * i <= num; i += 2) 
        if(num % i == 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) cout << "FastestFinger" << endl;
        else if(n == 2 || (n & 1)) cout << "Ashishgup" << endl;
        else {
            int cnt = 0;
            while(n % 2 == 0) n /= 2, cnt++;
            if(cnt == 1) {
                cout << (pr(n) ? "FastestFinger" : "Ashishgup") << endl;
            } else {    
                cout << (n > 2 ? "Ashishgup" : "FastestFinger") << endl;
            }
        }
    }
    return 0;
}