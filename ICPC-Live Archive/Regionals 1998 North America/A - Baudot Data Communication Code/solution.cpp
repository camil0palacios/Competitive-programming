#include <bits/stdc++.h>
using namespace std;

int main(){
    string sd, su, s;
    getline(cin, sd);
    getline(cin, su);
    while(cin >> s){
        int x = 0, idx = 4;
        bool flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(idx >= 0){
                x |= ((s[i]-'0') << (idx));
                idx--;
            }else{
                if(x == 27){
                    flag = 0;
                }
                else if(x == 31){
                    flag = 1;
                }
                else{
                    if(!flag){
                        cout << sd[x];
                    }else{
                        cout << su[x];
                    }
                }
                x = 0; idx = 4;
                x |= ((s[i]-'0') << (idx));
                idx = 3;
            }
        }
        if(x == 27){
            flag = 0;
        }
        else if(x == 31){
            flag = 1;
        }
        else{
            if(!flag){
                cout << sd[x];
            }else{
                cout << su[x];
            }
        }
        cout << endl;
    }
    return 0;
}