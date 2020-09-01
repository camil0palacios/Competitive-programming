#include <bits/stdc++.h>
using namespace std;

int v[5][5];
int ans;

void go(int u = 0, string s = "", int k = 5){
    if(k == 0){
        int tmp = 0;
        for(int i = 0; i <  5; i++){
            for(int j = i; j + 1 < 5; j+=2){
                tmp += (v[s[j] - '0'][s[j+1] - '0'] + v[s[j+1]-'0'][s[j]-'0']);
            }
        }
        ans = max(ans, tmp);
        return;
    }
    for(int i = 0; i < 5; i++){
        if( (u & (1 << i)) == 0){
            go(u|(1 << i), s + to_string(i), k - 1);
        }
    }
}

int main(){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> v[i][j];
        }
    }
    ans = 0;
    go();
    cout << ans << endl;
    return 0;
}