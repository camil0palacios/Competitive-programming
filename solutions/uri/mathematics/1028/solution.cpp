#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return (b == 0)? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int f1, f2;
        cin >> f1 >> f2;
        if(f1 > f2)cout << gcd(f1, f2) << endl;
        else cout << gcd(f2, f1) << endl;
    }
    return 0;
}