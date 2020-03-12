#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int z = 0, ps = 0, ng = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            z += x == 0;
            ps += (x > 0 ? x : 0);
            ng += (x < 0 ? x : 0);
        }
        int ans = z;
        ps += z;
        if(ps + ng == 0){
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}