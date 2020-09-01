#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k=1;
    while(cin >> n, n){
        int r = 0, h = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            if(tmp == 0)h++;
            else r++;
        }
        cout << "Case " << k << ": " << r - h << endl;
        k++;
    }
    return 0;
}