#include <bits/stdc++.h>
using namespace std;


long long fact(long long n){
    if(n == 0)return 1LL;
    else return n*fact(n-1);
}

int main(){
    long long n, m;
    while(cin >> n >> m){
        n = fact(n);
        m = fact(m);
        cout << n + m << endl;
    }
    return 0;
}