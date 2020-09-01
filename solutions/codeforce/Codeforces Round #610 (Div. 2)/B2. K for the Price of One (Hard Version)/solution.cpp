#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MX = 2e5 + 5;
int a[MX];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, p, k;
        cin >> n >> p >> k;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = 0, acc = 0;
        for(int i = 0; i <= k; i++){
            int sum = acc;
            if(acc > p)break;
            int cnt = i;
            for(int j = i + k - 1; j < n; j += k){
                if(sum + a[j] <= p){
                    cnt += k;
                    sum += a[j];
                }else{
                    break;
                }
            }
            acc += a[i];
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}