#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v[3][3];
    int n[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
            n[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            while(v[i][j]){
                if(i + 1 < 3)n[i+1][j] = !n[i+1][j];
                if(i - 1 >-1)n[i-1][j] = !n[i-1][j];
                if(j + 1 < 3)n[i][j+1] = !n[i][j+1];
                if(j - 1 >-1)n[i][j-1] = !n[i][j-1];
                n[i][j] = !n[i][j];
                v[i][j]--;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << n[i][j];
        }
        cout << endl;
    }
    return 0;
}