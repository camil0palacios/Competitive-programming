#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    while(k--){
        int c, n;
        cin >> c >> n;
        cout << c << " " << (n*(n+1)/2) + n << endl;
    }
    return 0;
}