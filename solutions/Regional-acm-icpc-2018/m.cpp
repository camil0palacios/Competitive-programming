#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = n;
    vector<int> v(n);
    for(auto &i: v)cin >> i;
    for(int i = 0; i < n - 1;i++){
        if(v[i] >= v[i+1])ans--;
    }
    cout << ans << endl;
    return 0;
}