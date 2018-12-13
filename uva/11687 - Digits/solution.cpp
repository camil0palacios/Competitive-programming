#include <bits/stdc++.h>
using namespace std;

int f(int n, int cont = 1){
    if(n == 1)return cont + 1;
    string s = to_string(n);
    return f(s.size(), cont + 1);
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin >> s && s[0] != 'E'){
        if(s.size() == 1 && s[0] == '1')cout << 1 << endl;
        else cout << f(s.size()) << endl;
    }
    return 0;
}