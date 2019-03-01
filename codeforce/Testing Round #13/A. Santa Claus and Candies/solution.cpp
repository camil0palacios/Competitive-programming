#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        int p = 1;
        while((p*(p+1))/2 <= n)p++;
        p--;
        cout << p << endl;
        for(int i = 1; i < p; i++){
            cout << i << " ";
            n -= i;
        }
        cout << n << endl; 
    }
    return 0;
}