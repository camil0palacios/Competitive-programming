#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        int ans = 0;
        if(a == b || a == c || a == d)ans++;
        if(b == c || b == d)ans++;
        if(c == d)ans++;
        cout << ans << endl;
    }
    return 0;
}