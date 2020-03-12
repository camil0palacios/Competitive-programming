#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int sx = 0, sy = 0, sz = 0;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        sx += x, sy += y, sz += z;
    }
    vector<int> v({sx, sy, sz}), vz({0, 0, 0});
    if(v == vz)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}