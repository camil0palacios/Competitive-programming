#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        double ans = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            ans += tmp;
        }
        ans = (ans/(n*100))*100.0;
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}