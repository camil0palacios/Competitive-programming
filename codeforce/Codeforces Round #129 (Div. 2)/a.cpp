#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        long long tmp, mmin = 1000000005, ans = 1, cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            if(tmp < mmin){
                mmin = tmp;
                ans = i; 
                cnt = 0;
            }
            if(mmin == tmp){
                cnt++;
            }
            
        }
        if(cnt == 1)cout << ans + 1 << endl;
        else cout << "Still Rozdil" << endl; 
    }
    return 0;
}