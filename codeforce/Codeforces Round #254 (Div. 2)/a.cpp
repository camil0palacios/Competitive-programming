#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        bool f = 0, k = m % 2;
        for(int i = 0; i < n; i++){
            if(!k)f ^= 1;
            for(int j = 0; j < m; j++){
                if(v[i][j] != '-'){
                    v[i][j] = (f ? 'B' : 'W'); 
                }
                f ^= 1;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}