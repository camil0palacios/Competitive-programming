#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int pal = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == s[i]){
                s.erase(i, 1);
                s.erase(i-1, 1);
                i-=2;
                pal++;
            }
        }
        if(pal % 2)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}