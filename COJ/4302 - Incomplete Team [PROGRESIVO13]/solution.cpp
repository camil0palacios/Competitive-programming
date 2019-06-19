#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int mcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        cout << mcm(n,m) << endl;
    }
    return 0;
}