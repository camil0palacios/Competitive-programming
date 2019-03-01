#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        int k = 0, j = 0;
        for(int i = 1; i <= n; i++){
            if(n % i == 0 &&  n/i >= 1 && n/i <= 9){
                j = n/i;
                k = i;
                break;
            }
        }
        cout << k << endl;
        for(int i = 0; i < k; i++)cout << j << " ";
        cout << endl;
    }
    return 0;
}