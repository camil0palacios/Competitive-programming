#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y, z;
    int a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    int gb = a + b, tot = a + b + c;
    if(a - x >= 0){
        gb -= x;
        tot -= x;
        if(gb - y >= 0){
            tot -= y;
            if(tot - z  >= 0){
                cout << "YES" << endl;
            }else cout << "NO" << endl;
        }else cout << "NO" << endl;
    }else cout << "NO" << endl;
    return 0;
}