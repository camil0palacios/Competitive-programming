#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[101][101];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++) {
            a[i][i] = a[i][(i + 1) % n] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) { 
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0; 
}