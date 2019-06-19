#include <bits/stdc++.h>
//#define endl '\n'
using namespace std;

void solve(){
    int n, m;
    cin >> m >> n;
    int ans = 0;
    if(m > n)swap(m,n);
    if(n == 1 || m == 1){
        ans = m*n;
    }
    else if(n == 2 || m == 2){
        if(n == m){
            ans = n*m;
        }
        else if(n % 2 == 1){
            ans = n + 1;
        }
        else if(n % 2 == 0){
            int x = n/2;
            if(x % 2 == 0){
                ans = (m*n)/2;
            }else{
                ans = m + n;
            }
        }
    }else{
        ans = ((m*n)+1)/2;
    }
    cout << ans << endl;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}