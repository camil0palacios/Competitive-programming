#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int k = n*2, g = 0;
        bool f = 0;
        for(int i = 0; i < n*2 + 1; i++){
            cout << string(k, ' ');
            for(int j = 0; j < g; j++){
                cout << j << " ";
            }
            for(int j = g; j >= 0; j--){
                cout << j << (j ? " " : "");
            }
            cout << endl;
            if(k == 0)f=1;
            if(f)k+=2,g--;
            else k-=2, g++; 
        }
    }
    return 0;
}