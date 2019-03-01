#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        while(n){
            if(n >= 7)n -= 7;
            else if(n >= 6)n -= 6;
            else if(n >= 5)n -= 5;
            else if(n >= 4)n -= 4;
            else if(n >= 3)n -= 3;
            else if(n >= 2)n -= 2;
            else n = 0;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}