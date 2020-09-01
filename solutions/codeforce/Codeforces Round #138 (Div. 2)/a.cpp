#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c;
    while(cin >> a >> b >> c){
        int ans = 4*(sqrt(a*b/c)+sqrt(a*c/b)+sqrt(b*c/a));
        cout << ans << endl;
    }
    return 0;
}