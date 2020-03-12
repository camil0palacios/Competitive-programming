#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int mxp = 0, mxk = 0;
    for(int i = 0; i < n; i++){
        int k, a;
        cin >> k >> a;
        mxk = max(mxk, k);
        int p = 1, acc = 0;
        while(p < a){
            p *= 4;
            acc++;
        }
        mxp = max(mxp, acc + k);
    }
    if(mxp == mxk){
        mxp++;
    }
    cout << mxp << endl;
    return 0;
}