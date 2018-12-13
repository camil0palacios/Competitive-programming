#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, h, w;
    while(cin >> n >> b >> h >> w){
        long long mmin = 26000001;
        while(h--){
            int p;
            bool flag = false;
            cin >> p;
            for(int i = 0; i < w; i++){
                int tmp; cin >> tmp;
                if(tmp >= n)flag = true;
            }
            if(flag && p*n <= b) mmin = min(mmin, (long long)p*n);
        }
        if(mmin == 26000001)cout << "stay home" << endl;
        else cout << mmin << endl;
    }
    return 0;
}