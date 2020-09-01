#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a,b;
    while(cin >> a >> b){
        int n = a.size();
        for(int i = 0; i < n ; i++){
            if(a[i] != b[i])cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}