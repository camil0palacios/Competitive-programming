#include <bits/stdc++.h>
using namespace std;

int n, a[2001];

bool check(int a, int b, int c){
    return (a < b + c) && (b < a + c) && (c < a + b);
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            int l = j+1, r = n;
            while(r-l > 1){
                int mid = (l+r)>>1;
                if(check(a[i],a[j],a[mid]))l = mid;
                else r = mid;
            }           
            if(check(a[i],a[j],a[l]))ans += (l-j);
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cout << "Case " << x << ": ";
        solve();
    }
    return 0;
}