#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<long long> v(n);
        long long mmax = 0;
        for(auto i = 0; i < n; i++){
            cin >> v[i];
            mmax = max(mmax, v[i]);
        }
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == mmax)y++;
            else{
                x = max(x, y);
                y = 0;
            }
        }   
        cout << max(x,y) << endl;
    }
    return 0;
}