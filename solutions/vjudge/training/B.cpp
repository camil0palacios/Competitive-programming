#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char g[51][51];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i - 1 >= 0 && i + 1 < n && j - 1 >= 0 && j + 1 < n && g[i][j] == '.' && 
                g[i-1][j] == '.' && g[i+1][j] == '.' && g[i][j-1] == '.' && g[i][j+1] == '.'){
                g[i][j] = g[i-1][j] = g[i+1][j] = g[i][j-1] = g[i][j+1] = '#';
            }
        }
    }
    bool flag = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '.'){
                flag = 0;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}