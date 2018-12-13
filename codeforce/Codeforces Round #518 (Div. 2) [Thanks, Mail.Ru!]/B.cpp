#include <bits/stdc++.h>
using namespace std;

int main(){
    long long b;
    cin >> b;
    int ans = 0;
    for(long long i = 1; i*i <= b ; i++)
        if(b % i == 0){
            if(i*i == b)ans++;
            else ans += 2;
        }
    cout << ans << endl;
    return 0;
}