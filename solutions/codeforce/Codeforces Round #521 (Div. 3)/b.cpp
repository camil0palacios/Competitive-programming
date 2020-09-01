#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v)cin >> i;
    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(v[i] == 0 && v[i-1] == 1 && v[i+1] == 1){
            v[i-1] = 0;
            v[i+1] = 0;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}