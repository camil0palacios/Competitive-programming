#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[104];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int tmp = 0;
        for(int j = i; j < n; j++){
            tmp ^= a[j];
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}