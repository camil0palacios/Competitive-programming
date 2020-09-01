#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while(n < m){
        m = (m % 2 ? m + 1 : m / 2); 
        ans++;
    }
    ans = ans + n - m;
    cout << ans << endl;
    return 0;
}