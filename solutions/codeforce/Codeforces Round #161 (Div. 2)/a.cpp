#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v[5][5];
    int x = 0, y = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> v[i][j];
            if(v[i][j] == 1) x = i, y = j;
        }
    }
    cout << abs(x-2) + abs(y-2) << endl;
    return 0;
}