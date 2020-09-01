#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[2*n + 1];
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        sort(a, a + 2*n);
        cout << a[n] - a[n - 1] << endl;
    }
    return 0;
}