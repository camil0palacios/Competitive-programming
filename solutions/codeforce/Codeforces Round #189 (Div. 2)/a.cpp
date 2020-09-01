#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        int flag = 0, i = 0;
        while(i < s.size() && !flag){
            flag = 1;
            if(s[i] == '1'){
                flag = 0;
                i++;
                if(i < s.size() && s[i] == '4'){
                    i++;
                    if(i < s.size() && s[i] == '4')i++;
                }
            }
        }
        if(i == s.size())cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}