#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

void sol() {
    int n;
    cin >> n;
    if(n < 30) {
        for(int i = 0; i < n; i++) {
            cout << i + 1 << ' ' << 1 << endl;
        }
        return;
    }
    n -= 30;
    int i = 0, k = 0; bool dir = 0;
    for(; i < 30; i++) {
        if((n >> i) & 1) {
            k++;
            if(!dir) {
                for(int j = 0; j <= i; j++) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            } else {    
                for(int j = i; j >= 0; j--) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                }
            }
            dir ^= 1;
        } else {
            cout << i + 1 << ' ' << (dir ? i + 1 : 1) << endl;
        }
    }
    for(int j = 0; j < k; j++, i++) {
        cout << i + 1 << ' ' << (dir ? i + 1 : 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ":" << endl;
        sol();
    }
    return 0;
}