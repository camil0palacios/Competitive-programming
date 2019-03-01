#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n && n){
        vector<int> v(n,-1);
        bool f = 1;
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            if(i + b > n || i + b < 0 || v[i + b] != -1){
                f = 0;
            }
            if(f)v[i+b] = a;
        }
        if(f){
            f = 0;
            for(int i = 0; i < n; i++){
                if(f)cout << " ";
                cout << v[i];
                f = 1;
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}