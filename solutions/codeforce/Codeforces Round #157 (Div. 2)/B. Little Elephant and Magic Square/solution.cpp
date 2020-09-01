#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int a[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 100000; i++){
        int sum = i + a[0][1] + a[0][2];
        int x = sum - a[1][0] - a[1][2];
        int y = sum - a[2][0] - a[2][1];
        if( (i + x + y) == sum){
            a[0][0] = i;
            a[1][1] = x;
            a[2][2] = y;
            break;
        }  
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}