#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[100005];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 1; i < n; i++){
        int idx = i;
        for(int j = 2; i + j <= n; j <<= 1){ 
            idx = j; 
        }
        a[i + idx] += a[i];
        ans += a[i];
        cout << ans << endl;
    }
    return 0;
}