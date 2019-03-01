#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int tram = 0, mmax = 0, a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            tram -= a;
            tram += b;
            mmax = max(mmax, tram);
        }
        cout << mmax << endl;
    }
    return 0;
}