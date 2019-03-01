#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<int> v(7);
        for(auto &i : v)cin >> i;
        int i = 1;
        while(1){
            n -= v[i-1];
            if(n <= 0)break;
            i++;
            if(i > 7)i = 1;
        }
        cout << i << endl;
    }
    return 0;   
}