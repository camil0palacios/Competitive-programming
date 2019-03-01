#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    while(cin >> n >> x >> y){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        if(x > y)cout << n << endl;
        else{
            int ans = 0;
            for(auto & i : v){
                if(i <= x)
                    ans++;
            }
            cout << ceil(ans/2.0) << endl;
        }
    }
    return 0;
}