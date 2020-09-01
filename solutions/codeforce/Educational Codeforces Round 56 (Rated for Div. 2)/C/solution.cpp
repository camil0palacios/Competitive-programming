#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        long long a[n + 1];
        for(int i = 1; i <= n/2; i++){
            long long x; cin >> x;
            if(i == 1){
                a[1] = 0;
                a[n] = x;
            }else{
                if(x == 1){a[i] = 0; a[n-i+1] = 1; continue;}
                else if(x > a[n-i+2]){
                    a[i] = x - a[n-i+2];
                    a[n-i+1] = a[n-i+2];
                    if(a[i] < a[i-1]){
                        a[i] = a[i-1];
                        a[n-i+1] = x - a[i-1];
                    }
                }else{
                    a[i] = a[i-1];
                    a[n-i+1] = x - a[i-1];
                }
            }
        }
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}