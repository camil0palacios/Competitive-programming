#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        vector<int> a(m), b(m);
        for(int i = 0 ; i < m; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        int tmp = n, mmax = 0, mmin = 0;
        while(tmp--){
            sort(a.begin(), a.end(), greater<int>());
            mmax += a[0];
            a[0]--;
        }
        tmp = n;
        while(tmp--){
            sort(b.begin(), b.end());
            mmin += b[0];
            b[0]--;
            if(b[0] == 0)b.erase(b.begin());
        }
        cout << mmax << " " << mmin << endl;
    }
    return 0;
}