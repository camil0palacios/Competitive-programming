#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long m = 1000000007;

long long rdx(int k, int n){
    long long f[n+1];
    long long acc = 0;
    for(int i = 0; i <= k; i++){
        if(i > n)return 1;
        f[i] = 1;
        acc += 1;
    }
    for(int i = k + 1 ; i <= n; i++){
        f[i] = acc - f[i-k-1];
        if(f[i] < 0)f[i] += m;
        acc = (acc + f[i]) % m;
        acc = acc - f[i-k-1];
        if(acc < 0)acc += m;
    }
    return f[n];
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long rn;
    int n;
    while(cin >> rn >> n){
        for(int i = 100; i >= 2; i--){
           long long ans = rdx(i, n);
           if(ans == rn){
               cout << i << endl;
               break;
           } 
        }   
    }
    return 0;
}