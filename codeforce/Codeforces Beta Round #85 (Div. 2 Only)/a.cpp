#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    while(cin >> a >> b){
        int n = a.size(), flag = 0;
        for(int i = 0; i < n; i++){
            char l = tolower(a[i]), r = tolower(b[i]);
            if(l != r){
                if(l < r){
                    flag = -1;
                }else{
                    flag = 1;
                }
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}