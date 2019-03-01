#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        sort(v.begin(), v.end());
        int t = 0;
        long long mmin = 3000005;
        for(int i = 1; i <= 100; i++){
            long long s = 0;
            for(int j = 0; j < n; j++){
                if(abs(v[j] - i) > 1)
                    s += abs(v[j] - i)-1;
            }
            if(s < mmin){
                mmin = s;
                t = i;
            }
        }
        cout << t << " " << mmin << endl;
    }
    return 0;
}