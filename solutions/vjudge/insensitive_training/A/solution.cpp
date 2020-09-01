#include <bits/stdc++.h>
using namespace std;

int main(){

    int s;
    while(cin >> s){
        if(s <= 90)cout << "0 No punishment" << endl;
        else if(s >= 91 && s <= 110 ){
            s = (s - 90)*300;
            cout << s << " Warning" << endl;
        }
        else if(s > 110){
            s = (s - 90)*500;
            cout << s << " License removed" << endl;
        }
    }
    return 0;   
}