#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n, n){
        int dir = 0;
        for(int i = 1; i < n; i++){
            string s; cin >> s;
            if(s == "+z"){
                if(dir == 0)dir = 4;
                else if(dir == 1)dir = 5;
                else if(dir == 4)dir = 1;
                else if(dir == 5)dir = 0;
            }
            if(s == "-z"){
                if(dir == 0)dir = 5;
                else if(dir == 1)dir = 4;
                else if(dir == 4)dir =  0;
                else if(dir == 5)dir = 1;
            }
            if(s == "+y"){
                if(dir == 0)dir = 2;
                else if(dir == 1)dir = 3;
                else if(dir == 2)dir = 1;
                else if(dir == 3)dir = 0;
            }
            if(s == "-y"){
                if(dir == 0)dir = 3;
                else if(dir == 1)dir = 2;
                else if(dir == 2)dir = 0;
                else if(dir == 3)dir = 1;
            }
        }
        if(dir == 0)cout << "+x";
        else if(dir == 1)cout << "-x";
        else if(dir == 2)cout << "+y";
        else if(dir == 3)cout << "-y";
        else if(dir == 4)cout << "+z";
        else if(dir == 5)cout << "-z";
        cout << endl;
    }
    return 0;
}   