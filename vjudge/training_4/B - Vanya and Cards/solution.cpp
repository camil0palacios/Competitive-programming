#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, x, sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
    }
    if(sum < 0)sum = -sum;
    int ans = (sum / k) + (sum % k == 0 ? 0 : 1);
    cout << ans << endl;
    return 0;
}