#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    while(cin >> n >> k){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        bool b = 1;
        for(int i = k - 1; i < v.size(); i++){
            if(v[k-1] != v[i]){
                b = 0;
                break;
            }
        }
        if(b){
            int _k = 0;
            for(int i = k - 1; i >= 0 && v[i] == v[k-1]; i--){
                _k++;
            }
            
            cout << k - _k << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}