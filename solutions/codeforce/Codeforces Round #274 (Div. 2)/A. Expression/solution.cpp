#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int mmax(vector<int> v){
    int mx = 0;
    for(int i = 0; i < v.size(); i++){
        mx = max(mx, v[i]);
    }
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v{a*b*c, (a + b)*c, a*(b + c), a + b + c};
    int ans = mmax(v);
    cout << ans << endl;
    return 0;
}