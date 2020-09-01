#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        int m[27];
        memset(m, 0, sizeof m);
        for(auto & i : s)m[i-'a']++;
        string a, b;
        for(int i = 0; i < 26; i+=2){
            while(m[i]--){
                a += 'a'+i;
            }
        }
        for(int i = 1; i < 26; i+=2){
            while(m[i]--){
                b += 'a'+i;
            }
        }
        if(abs(a.back()-b.front()) > 1)cout << a << b << endl;
        else if(abs(a.front()-b.back()) > 1)cout << b << a << endl;
        else cout << "No answer" << endl;
    }
    return 0;
}