#include <bits/stdc++.h>
using namespace std;

int main(){

    int b, k;
    while(cin >> b >> k){
        vector<int> v(k, 1);
        v[0] = 1;
        for(int i = 1; i < k; i++){
            v[i] = v[i-1]*b;
        }
        long long ans = 0;
        int l = k-1;
        for(int i = 0; i < k; i++){
            int tmp; cin >> tmp;
            ans += tmp*v[l];
            l--;
        }
        if(ans % 2 == 0)cout << "even" << endl;
        else cout << "odd" << endl;
    }
}