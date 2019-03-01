#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        string s[m];
        for(int i = 0; i < m; i++)cin >> s[i];
        for(int i = 0; i < 2*n; i++){
            for(int j = 0; j < 2*m; j++){
                cout << s[j/2][i/2];
            }
            cout << endl;
        }
    }
    return 0;   
}