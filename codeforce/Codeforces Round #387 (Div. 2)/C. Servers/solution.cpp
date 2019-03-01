#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, q, t, k, d;
    while(cin >> n >> q){
        int a[101] = {0}, b[105] = {0};
        for(int i = 0; i < q; i++){
            cin >> t >> k >> d;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(a[j] <= t)b[cnt++] = j;
            }
            if(cnt < k)cout << -1 << endl;
            else{
                int res = 0;
                for(int j = 0; j < k; j++){
                    a[b[j]] = t + d;
                    res += b[j] + 1;
                }
                cout << res << endl;
            }
        }
    }    
    return 0;
}