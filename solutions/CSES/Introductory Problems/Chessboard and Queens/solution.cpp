#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int n = 8;
char a[n][n];

bool notattack(vector<int> & pos, int i, int j) {
    for(int k = 0; k < i; k++) {
        if(abs(k - i) == abs(pos[k] - j) || j == pos[k]) return 0;
    }
    return 1;
}

int ans = 0;

void backtrack(int i, vector<int> & pos) {
    if(i == n) {
        ans++;
        return;
    }
    for(int j = 0; j < n; j++) {
        if(notattack(pos, i, j) && a[i][j] != '*') {
            pos[i] = j;
            backtrack(i + 1, pos);    
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> a[i][j];
    vector<int> pos(8);
    backtrack(0, pos);
    cout << ans << endl;
    return 0;
}