#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int ans = 0, a, b, c;
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c;
            if(a && b)ans++;
            else if(b && c)ans++;
            else if(a && c)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}