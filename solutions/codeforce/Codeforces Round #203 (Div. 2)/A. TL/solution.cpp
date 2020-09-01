#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    while(cin >> n >> m){
        int mmin = 101, mmax = 0;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            mmin = min(mmin, tmp);
            mmax = max(mmax, tmp);
        }
        int _mmin = 101;  
        for(int i = 0; i < m; i++){
            int tmp;
            cin >> tmp;
            _mmin = min(_mmin, tmp);
        }
        if(n == 1)mmin = mmax;
        if(mmin * 2 < _mmin && mmax < _mmin){
            cout << max(mmax, 2*mmin) << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}