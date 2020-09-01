#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cout << 3*n + i << " ";
        }
        cout << endl;
    }
    return 0;
}