#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<int> v(n), u(n,0);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end(), greater<int>());
        int y = v[0];
        set<int> s;
        for(int i = 0; i < n; i++){
            if(y % v[i] == 0 && !s.count(v[i])){
                u[i] = 1;
                s.insert(v[i]);
            }
        }
        int x = v[0];
        for(int i = 0; i < n; i++){
            if(u[i] != 1){
                x = v[i];
                break;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}