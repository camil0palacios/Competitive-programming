#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k, mmax;
        cin >> k >> mmax;
        for(int j = 0; j < k - 1; j++){
            int tmp; cin >> tmp;
            mmax = max(mmax, tmp);
        }
        cout << "Case " << i+1 << ": " << mmax << endl;
    }
    return 0;
}