#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k = 1;
    cin >> n;
    while(n--){
        int l, w, h; cin >> l >> w >> h;
        cout << "Case " << k << ": ";
        if(l <= 20 && w <= 20 && h <= 20)cout << "good";
        else cout << "bad";
        cout << endl;
        k++;
    }
    return 0;
}