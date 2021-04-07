#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a[3];
        for(int i = 0; i < 3; i++){
            cin >> a[i];
        }
        sort(a, a + 3);
        if(a[0] + a[1] >= a[2] - 1)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}