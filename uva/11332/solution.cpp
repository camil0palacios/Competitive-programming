#include <bits/stdc++.h>
using namespace std;

int f(long long n){
    if(n >= 0 && n <= 9)return n;
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return f(sum);
}   

int main(){
    long long n;
    while(cin >> n, n){
        cout << f(n) << endl;
    }
    return 0;
}