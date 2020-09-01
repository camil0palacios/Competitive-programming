#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        vector<int> v(n);
        for(auto & i : v)cin >> i;
        int mmin = 1001;
        int s1, s2 = 0;
        for(int i = 0; i < n - 1; i++){
            if(mmin > abs(v[i]-v[i+1])){
                s1 = i + 1;
                s2 = i + 2;
                mmin = abs(v[i] - v[i+1]);
            }
        }
        if(mmin > abs(v[0] - v[n-1])){
            s1 = n;
            s2 = 1;
        }
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}