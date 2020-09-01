#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);
        int sum = 0, mmin;
        for(auto &i : v)cin >> i, sum += i;
        sort(v.begin(), v.end());
        mmin = sum;
        for(int i = 1; i < n; i++){
            for(int x = 2; x <= v[i]; x++){
                if(v[i] % x == 0){
                    mmin = min(mmin, sum - v[0] - v[i] + v[0]*x + v[i]/x);
                    int o = v[i]/x;
                    mmin = min(mmin, sum - v[0] - v[i] + v[0]*o + v[i]/o);
                }
            }
        }
        cout << mmin << endl;
    }
    return 0;
}