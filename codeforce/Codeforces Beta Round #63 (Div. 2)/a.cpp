#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int x = 0, y = 0, z = 0;
        while(n--){
            int _x, _y, _z;
            cin >> _x >> _y >> _z;
            x += _x;
            y += _y;
            z += _z;
        }
        if(x == 0 && y == 0 && z == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}