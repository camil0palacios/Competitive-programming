#include <bits/stdc++.h>
using namespace std;

int main(){

    string a, b;
    while(cin >> a >> b){
        bool f = 1;
        if(a.size() == b.size()){
            bool f = 1;
            for(int i = 0; i < a.size(); i++){
                bool va = 0, vb = 0;
                if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                    va = 1;
                if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u')
                    vb = 1;
                if(va != vb){
                    f = 0;
                    break;
                }
            }
            if(f)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}