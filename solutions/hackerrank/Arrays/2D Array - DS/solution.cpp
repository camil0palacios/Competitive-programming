#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a[6][6];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cin >> a[i][j];
        }
    }
    int ans = -100;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(i + 2 < 6 && j + 2 < 6){
                int res = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
                ans = max(ans, res);
            }
        }
    }
    cout << ans << endl;
    return 0;
}