#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    while(cin >> s){
        
        int a = 1, b = 1;
        for(int i = 1; i < s.size(); i++){
            a = i;
            b = ceil(s.size()/(double)a);
            if(b <= 20)break;
        }

        cout << a << " " <<  b << endl;
        int pt = (b * a) - s.size(), idx = 0;
        for(int i = 0; i < pt; i++ ){
            s.insert(s.begin() + idx , '*');
            idx += b;
        }
        for(int i = 0; i < b*a ; i+= b){
            for(int j = 0; j < b; j++){
                cout << s[i+j];
            }
            cout << endl;
        }
    }
    return 0;
}