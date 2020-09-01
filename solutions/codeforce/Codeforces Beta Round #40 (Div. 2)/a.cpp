#include <bits/stdc++.h>
using namespace std;

int main(){

    string s, t;
    while(cin >> s >> t){
        int n = s.size();
        bool flag = 1;
        for(int i = 0, j = s.size() - 1; i < n; i++, j--){
            if(s[i] != t[j]){
                flag = 0;
                break;
            }
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}