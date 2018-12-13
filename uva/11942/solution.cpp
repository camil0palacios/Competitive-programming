#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    while(n--){
        int cur;
        int up = 0, down = 0;
        cin >> cur;
        for(int i = 0; i < 9; i++){
            int tmp; cin >> tmp;
            if(cur < tmp)up++;
            else down++;
            cur = tmp;
        }
        if(up == 9 || down == 9)cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
    
    return 0;
}