#include <bits/stdc++.h>
using namespace std;

int a[101];

int solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && a[j] != (i+1)){
            j++;
        }
        if(i != j){
            swap(a[i],a[j]);
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}