#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n], ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool flag = 1;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] - (i + 1) > 2){
                cout << "Too chaotic" << endl;
                flag = 0;
                break;
            }
            for(int j = max(0, a[i] - 2); j < i; j++)
                if(a[j] > a[i]){
                    ans++;
                }
        }
        if(flag)cout << ans << endl;
    }
    return 0;
}