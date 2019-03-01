#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s){ 
        string s1;
        for(int i = 0; i < s.size(); i++){
            s1 += s[i];
        }
        bool f = (s.size() % 2 == 0 ? 1 : 0);
        int l = 0, r = s.size()-1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(f){
                s1[i] = s[r];
                r--;
                f = 0;
            }else{
                s1[i] = s[l];
                l++;
                f = 1;
            }
        }
        cout << s1 << endl;
    }
    return 0;
}