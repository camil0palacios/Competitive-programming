#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, y1, y2; 
        cin >> n ;
        cin >> y1 >> y2;
        int dif = abs(y1 - y2);
        bool flag = true;
        while(--n){
            cin >> y1 >> y2;
            if(abs(y1 - y2) != dif){
                flag = false;
            }
        }
        if(flag)cout << "yes" << endl;
        else cout << "no" << endl;
        if(t)cout << endl;
    }
    return 0;
}