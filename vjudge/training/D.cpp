#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c){
    return (a < b + c) && (b < a + c) && (c < a + b);
}

int main(){

    int n;
    cin >> n;
    int ans = 0;
    for(int c = n; c >= 1; c--){
        for(int b = c; b >= 1; b--){
            int a = c ^ b;
            if((a <= b) && (b <= c) && check(a,b,c))ans++;
        }
    }
    cout << ans << endl;
    return 0;
}