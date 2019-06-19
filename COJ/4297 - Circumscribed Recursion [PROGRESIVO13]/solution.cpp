#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, R, k;
    cin >> t;
    while(t--){
        cin >> R >> k;
        if(k % 2){
            cout << (1LL << (k/2))*(R*R) << "PI" << endl;
        }else{
            cout << (1LL << ((k/2) + 1))*(R*R) << endl;
        }
    }
    return 0;
}