#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){
        int j = 0;
        bool f = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1')f = 1;
            if(f && s[i] == '0'){
                j = i;
                break;
            }
        }
        if(j){
            for(int i = 0; i < s.size(); i++){
                if(i != j)
                    cout << s[i];
            }
        }else{
            for(int i = 0; i < s.size() - 1; i++)
                cout << s[i];
        }
        cout << endl;
    }
    return 0;
}