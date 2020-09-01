#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    while(cin >> n){
        vector<int> v(1001);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            v[x]++;
        }
        bool f = 1;
        for(int i = 0; i < 1001; i++){
            if(v[i]*2 - 1 > n)f = 0;
        }
        if(f)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}