#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int w = 0, b = 0;
        char c[n][m]; bool col = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1)col = 1;
            else col = 0;
            for(int j = 0; j < m; j++) {
                w += col;
                b += !col;
                c[i][j] = col ? 'W' : 'B';
                col ^= 1;
            }
        }
        if(w == b) {
            for(int i = m - 1; i >= 0; i--) {
                if(c[n - 1][i] == 'W'){
                    c[n - 1][i] = 'B'; 
                    break;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << c[i][j];   
            }
            cout << endl;
        }
    }
    return 0;
}