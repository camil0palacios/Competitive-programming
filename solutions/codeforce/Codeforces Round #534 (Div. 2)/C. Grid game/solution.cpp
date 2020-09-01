#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        int a = 0, b = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cout << "1 " << a + 1 << endl;
                a = (a+1)%4;
            }else{
                cout << "3 " << b + 1 << endl;
                b = (b+2)%4;
            }
        }
    }
    return 0;
}