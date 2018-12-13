#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        if(s == "1" || s == "4" || s == "78")cout << "+";
        else if(s[s.size()-2] == '3' && s[s.size()-1]  == '5')cout << "-";
        else if(s[0] == '9' && s[s.size()-1] == '4')cout << "*";
        else if(s[0] == '1' && s[1] == '9' && s[2] == '0')cout << "?";
        else cout << '+';
        cout << endl;
    }
    return 0;
}