#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0; cin >> n;
        while(n--){
            int size, anim, fri;
            cin >> size >> anim >> fri;
            ans += (size*fri);
        }
        cout << ans << endl;
    }
    return 0;
}