#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += v[i];
        }
        int mmin = sum, j = 1;
        for(int i = k; i < n; i++){
            sum -= v[i-k];
            sum += v[i];
            if(sum < mmin){
                mmin = sum;
                j = i - k + 2;
            }
        }
        cout << j << endl;
    }
    return 0;
}