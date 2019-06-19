#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    bool flag = 0;
    for(int i = l; i <= r; i++){
        if(i % k == 0){
            int n = i/k;
            if(x <= n && n <= y){
                flag = 1;
                break;
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}