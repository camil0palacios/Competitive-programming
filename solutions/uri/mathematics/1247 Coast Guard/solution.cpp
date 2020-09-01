#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double d, v1, v2;
    while(cin >> d >> v1 >> v2){
        long double h = sqrt(d*d + 144);
        if(12 / v1 >= h / v2)cout << 'S' << endl;
        else cout << 'N' << endl;
    }
    return 0;
}