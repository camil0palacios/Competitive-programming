#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<int> v(n+2);
        for(int i = 1; i <= n; i++)cin >> v[i];
        int ans = 0,k = 0;
        v[0] = 0; v[n+1] = 1001;
        for(int i = 1; i <= n; i++){
            if(v[i] - 1 == v[i-1] && v[i] + 1 == v[i+1])k++, ans = max(ans,k);
            else k = 0;
        }
        cout << ans << endl;
    }
    return 0;
}