#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int frq[3]; 
        long long x;
        memset(frq, 0, sizeof frq);
        for(int i = 0; i < n; i++){
            cin >> x;
            frq[(x % 3)]++;
        }
        int ans = 0;
        if(frq[1] && frq[2]){
            int x = min(frq[1], frq[2]);
            ans = x;
            frq[1] -= x;
            frq[2] -= x;
        }
        ans += (frq[1]/3);
        ans += (frq[2]/3);
        ans += frq[0];
        cout << ans << endl;

    }
    return 0;
}