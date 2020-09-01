#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin >> n >> k){
        if(n < 2*k + 1){
            cout << -1 << endl;
        }
        else {
            cout << n*k << endl;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < k; j++){
                    int tmp = (i+j+1)%n;
                    cout << i + 1 << " " << tmp + 1 << endl;
                }
            }
        }
    }
    return 0;
}