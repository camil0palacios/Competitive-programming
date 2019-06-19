#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, y, z;
    cin >> x >> y >> z;
    long long ans = (x/z), mmin = 0;
    x %= z;
    ans += (y/z);
    y %= z;
    if(x < y)swap(x, y);
    if((x + y)/z > 0){
        ans += (x+y)/z;
        mmin = y - ((x+y) % z);
    }
    cout << ans << " " << mmin << endl;
    return 0;
}