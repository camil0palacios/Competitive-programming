#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int r = 1, c = 1;
    cout << (n/2) + 1 << endl;
    for(int i = 1; i <= n; i++){
        cout << r << " " << c << endl;
        if(i % 2){
            c++;
        }else r++;
    }
    return 0;   
}