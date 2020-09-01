#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b && a != -1 && b != -1){
        int res1 = (a < b) ? a + 99 - b + 1 : 99 - a + b + 1;
        int res2 = abs(a - b);
        if(res1 < res2)cout << res1 << endl;
        else cout << res2 << endl;
    }
    return 0;
}