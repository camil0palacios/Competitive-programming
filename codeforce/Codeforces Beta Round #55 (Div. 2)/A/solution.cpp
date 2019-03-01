#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int up = 0, low = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')low++;
            else if(s[i] >= 'A' && s[i] <= 'Z')up++;
        }
        if(up <= low){
            for(int i = 0; i < s.size(); i++)
                cout << char(tolower(s[i]));
            cout << endl;
        }else{
            for(int i = 0; i < s.size(); i++)
                cout << char(toupper(s[i]));
            cout << endl;
        }
    }
    return 0;
}