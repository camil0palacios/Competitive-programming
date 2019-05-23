#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[101], ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        if((a[i] == 2 && a[i-1] == 3) || (a[i] == 3 && a[i-1] == 2)){
            cout << "Infinite" << endl;
            return 0;
        }
        if((a[i] == 1 && a[i-1] == 2) || (a[i] == 2 && a[i-1] == 1)){
            ans += 3;
            if(i > 2 && a[i-2] == 3)ans--;
        }
        else if((a[i] == 1 && a[i-1] == 3) || (a[i] == 3 && a[i-1] == 1))ans += 4; 
    }
    cout << "Finite" << endl << ans << endl;
    return 0;
}