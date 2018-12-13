#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<int> v(3);
        for(auto &i: v)cin >> i;
        sort(v.begin(), v.end());
        cout << "Case " << i+1 << ": " << v[1] << endl;
    }
    return 0;
}