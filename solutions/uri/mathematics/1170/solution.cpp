#include <bits/stdc++.h>
using namespace std;

int half(double x){
    int ans = 0;
    while(x > 1.0){
        x /= 2;
        ans ++;
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    while(n--){
        double x; cin >> x;
        cout << half(x) << " dias"<< endl;
    }
    return 0;
}