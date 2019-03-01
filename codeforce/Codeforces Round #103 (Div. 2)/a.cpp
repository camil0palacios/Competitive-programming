#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int k = 0, j = 0, mmin = 101, mmax = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            if(tmp <= mmin)mmin = tmp, k = i;
            if(tmp > mmax)mmax = tmp, j = i;
        }
        if(k == j)cout << 0 << endl;
        else if(k < j){
            cout << j + (n - 1 - k) - 1 << endl;
        }else{
            cout << j + (n - 1 - k) << endl;
        }
    }
    return 0;
}