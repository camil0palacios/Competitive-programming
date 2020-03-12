#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int mod = 10;
int v[4] = {2,4,8,6};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long k;
        int d1, d2;
        cin >> k;
        cin >> d1 >> d2;
        long long sum = 0;
        if(k > 3){
            sum = (long long)((k-3)/4)*((2*(d1+d2))%mod + (4*(d1+d2))%mod + (8*(d1+d2))%mod + (6*(d1+d2))%mod);
            int res = (k-3) % 4;
            for(int i = 0; i < res; i++){
                sum = (sum + (v[i]*(d1+d2))%mod);
            }
        }
        sum = (sum + d1 + d2);
        if(k >= 3)sum = (sum + (d1 + d2) % mod);
        if(sum % 3 == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}