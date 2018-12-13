#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, c, seq = 1;
    while(cin >> n >> m >> c, n, m, c){
        vector<int> v(n);
        vector<bool> t(n, 0);
        int sum = 0, mmax = 0, flag = 1;
        for(auto &i : v)cin >> i;
        for(int i = 0; i < m; i++){
            int tmp;
            cin >> tmp; tmp--;
            if(!t[tmp]){
                sum += v[tmp];
                t[tmp] = 1;
            }else{
                sum -= v[tmp];
                t[tmp] = 0;
            }
            if(sum > c)flag = 0;
            mmax = max(mmax, sum);
        }

        cout << "Sequence " << seq++ << endl;
        if(flag){
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << mmax << " amperes." << endl << endl;
        }
        else cout << "Fuse was blown." << endl << endl;
    }
    return 0;
}