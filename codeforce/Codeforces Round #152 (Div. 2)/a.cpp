#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            if(a)l++;
            if(b)r++;
        }
        int ans = 0;
        if(n - r <= r)ans += n - r;
        else ans = r;
        if(n - l <= l)ans += n - l;
        else ans += l;
        cout << ans << endl;
    }
    return 0;
}