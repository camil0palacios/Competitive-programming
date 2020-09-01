#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    while(cin >> n >> m){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        int mmin = 100005;
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < m - j; i++)sum += v[i];
            int aux = sum;
            for(int i = m - j; i < n; i++){
                sum = sum - v[i-(m-j)] + v[i];
                aux = min(aux, sum);
            }
            mmin = min(mmin, aux);
        }
        if(-1*mmin > 0)cout << -1*mmin << endl;
        else cout << 0 << endl;
    }
    return 0;
}