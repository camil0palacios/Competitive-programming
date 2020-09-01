#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        int x = 0;
        for(int i = 0; i < n; i++){
            string tmp; cin >> tmp;
            if(tmp == "++X" || tmp == "X++")x++;
            else x--;
        }
        cout << x << endl;
    }
    return 0;
}