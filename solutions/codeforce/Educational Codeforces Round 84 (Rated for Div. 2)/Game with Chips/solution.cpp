#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < 2*k; i++){
        int x, y; cin >> x >> y;
    }
    cout << n*(m - 1) + n + m - 2 + n - 1 << endl;
    for(int i = 0; i < n - 1; i++)cout << 'U';
    for(int i = 0; i < m - 1; i++)cout << 'L';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(i & 1)cout << "L";
            else cout << "R";
        }
        if(i < n - 1)cout << "D";
    }
    return 0;
}