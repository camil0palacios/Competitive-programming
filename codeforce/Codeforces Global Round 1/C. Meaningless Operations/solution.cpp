#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n, b = 0, i = 0;
        cin >> n;
        int a = n;
        while(a){
            if((a & 1) == 0)
                b |= (1 << i);
            a >>= 1;
            i++;
        }
        if(b == 0){
            a = 1;
            for(int i = 2; i*i <= n; i++){
                if(n % i == 0){
                    a = n/i;
                    break;
                }
            }
            cout << a << endl;
        }else{
            cout << (n^b) << endl;
        }
    }
    return 0;
}