#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, s, t;
        cin >> n >> s >> t;
        long long x = max(s, t);
        long long y = min(s, t);
        if(x >= n && y >= n){
            cout << 1 << endl;
        }
        else if(x >= n){
            cout << x - y + 1 << endl;
        }
        else if(x + y > n){
            cout << x - (x + y - n) + 1 << endl;
        }else{
            cout << x + 1 << endl;
        }
    }
    return 0;
}