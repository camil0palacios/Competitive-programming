#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int y, b, r;
    while(cin >> y >> b >> r){
        int ans = 0;
        for(int i = 1;  i <= y; i++){
            if(i + 1 <= b && i + 2 <= r)
                ans = max(ans, i + 1 + i + 2 + i);
        }
        cout << ans << endl;
    }
    return 0;
}