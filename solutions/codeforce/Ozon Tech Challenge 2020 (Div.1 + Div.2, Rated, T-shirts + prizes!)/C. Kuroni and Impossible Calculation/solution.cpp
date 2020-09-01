#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n > m){
        cout << 0 << endl;
    } else {
        long long ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = (ans * abs(a[i] - a[j])) % m;  
            }
        }
        cout << ans << endl;
    }
    return 0;
}