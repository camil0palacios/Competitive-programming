#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void print_1(string & s){
    cout << ".";
    for(int i = 0; i < s.size(); i++){
        cout << '.';
        if((i+1) % 3 == 0){
            cout << '*';
        }else{
            cout << '#';
        }
        cout << '.';
        if(i < s.size()-1)cout << '.';
    }
    cout << "." << endl;
}

void print_2(string & s){
    cout << '.';
    for(int i = 0; i < s.size(); i++){
        if((i+1) % 3 == 0){
            cout << "*.*";
        }else{
            cout << "#.#";
        }
        cout << '.';
    }
    cout << endl;
}

int main(){
    string s;
    cin >> s;
    print_1(s);
    print_2(s);
    cout << '#';
    for(int i = 0; i < s.size(); i++){
        cout << '.' << s[i] << '.';
        if((i+1) % 3 == 0 || (i+1 < s.size() && (i+2) % 3 == 0))cout << '*';
        else cout << '#';
    }
    cout << endl;
    print_2(s);
    print_1(s);
    return 0;   
}