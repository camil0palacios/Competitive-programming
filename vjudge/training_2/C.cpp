#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    if(k <= 36){
        while(k > 0){
            if(k >= 2){
                cout << '8';
                k -= 2;
            }
            else{
                cout << '6';
                k--;
            }
        }
        cout << endl;
    }else cout << -1 << endl;
    return 0;
}