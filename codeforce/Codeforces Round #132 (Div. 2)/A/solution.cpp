#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<int> a(n);
        for(auto & i : a)cin >> i;
        int m, b, mmax = 0, cnt = 0;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> b;
            for(int j = 0; j < n; j++){
                double r = double(b)/a[j];
                int aux = r;
                if(r == double(aux)){
                    if(mmax == aux)cnt++;
                    else if(mmax < aux){
                        cnt = 1;
                        mmax = aux;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}