#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int r[50], c[50];

char change(char cur) {
    return cur == 'B' ? 'W' : 'B';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i = 0; i < a; i++) {
        cin >> r[i];
    }
    for(int i = 0; i < b; i++) {
        cin >> c[i];
    }
    vector<int> x(n + 1, 0), y(m + 1, 0);
    int sum = 0;
    for(int i = 0; i < a; i++) {
        sum += r[i];
        x[sum] = 1; 
    }
    sum = 0;
    for(int i = 0; i < b; i++) {
        sum += c[i];
        y[sum] = 1;
    }
    char mat[n + 1][m + 1];
    char cur = 'B';
    for(int i = 0; i < n; i++) {
        if(x[i]) cur = change(cur);
        for(int j = 0; j < m; j++) {
            mat[i][j] = cur;
        }   
    }
    for(int i = 0; i < n; i++) {
        cur = mat[i][0];
        for(int j = 0; j < m; j++) {
            if(y[j]) cur = change(cur);
            mat[i][j] = cur;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}