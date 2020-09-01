#include <bits/stdc++.h>
using namespace std;

int main(){
    double u;
    int h, d, f;
    while(cin >> h >> u >> d >> f, h){
        int ans = 1;
        double cur = 0.0, ffact = u*(f/100.0);
        while(true){
            cur += u;
            if(u > 0)u -= ffact;
            if(cur > h)break;
            cur -= d;
            if(cur < 0)break;
            ans++;
        }
        if(cur > 0)cout << "success on day ";
        else cout << "failure on day ";
        cout << ans << endl;
    }
    return 0;
}