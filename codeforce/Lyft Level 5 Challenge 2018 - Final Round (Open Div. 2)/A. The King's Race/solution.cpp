#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, x, y;
    while(cin >> n >> x >> y){
        long double a = sqrt(ld(1-x)*ld(1-x) + ld(1-y)*ld(1-y));
        long double b = sqrt(ld(n-x)*ld(n-x) + ld(n-y)*ld(n-y));
        if(a == b)cout << "White" << endl;
        else if(a < b)cout << "White" << endl;
        else cout << "Black" << endl;
    }
    return 0;
}