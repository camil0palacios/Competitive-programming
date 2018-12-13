#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        long long a, b, k;
        cin >> a >> b >> k;
        if(k % 2 == 0)cout << a*(k/2) - b*(k/2) << endl;
        else {
            long long tmp = k/2;
            cout << a*(k-tmp) - b*(tmp) << endl;
        }
    }
    return 0;
}