#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c = 0,x;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            if(a > 0)a--;
            else if(b > 0)b--, c++;
            else if(c > 0)c--;
            else ans++;
        }
        else if(x == 2 && b > 0){
            b--;
        }else{
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}