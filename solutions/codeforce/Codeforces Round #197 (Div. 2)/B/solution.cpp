#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    while(cin >> n >> m){
        long long ans = 0, tmp, i = 1;
        while(m--){
            cin >> tmp;
            if(tmp < i)ans += (n - i) + tmp;
            else if(tmp > i)ans += (tmp - i);
            i = tmp;
        }
        cout << ans << endl;
    }
    return 0;
}