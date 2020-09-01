#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, ns;
    cin >> s >> s;
    int it = 0, i = 0;
    ns += s[0];
    while(i < s.size()){
        if((it+1) % 2 != 0 && ns[it] == s[i]){
            while(i < s.size() && ns[it] == s[i]){
                i++;
            }
            if(i == s.size())break;
        }
        ns += s[i];
        it++;
        i++;
    }
    if(ns.size()%2 != 0){
        ns = ns.substr(0,ns.size()-1);
    }
    cout << s.size()-ns.size() << endl;
    cout << ns << endl;
    return 0;
}