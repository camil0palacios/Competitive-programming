#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k;
char a[101][101];
int tmp[101][101];

bool check(int i, int j){
    for(int it = j; it < j + k; it++){
        if(a[i][it] == '#')return 0;
    }
    return 1;
}

bool check2(int i, int j){
    for(int it = i; it < i + k; it++){
        if(a[it][j] == '#')return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0, xx = 0, yy = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + k <= n && check(i, j)){
                for(int x = j; x < j + k; x++){
                    tmp[i][x]++;
                    if(ans < tmp[i][x]){
                        ans = tmp[i][x];
                        xx = i, yy = x;
                    }    
                }
            }
            if(i + k <= n && check2(i, j)){
                for(int x = i; x < i + k; x++){
                    tmp[x][j]++;
                    if(ans < tmp[x][j]){
                        ans = tmp[x][j];
                        xx = x, yy = j;
                    }
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << tmp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << xx + 1 << ' ' << yy + 1 << endl;
    return 0;
}