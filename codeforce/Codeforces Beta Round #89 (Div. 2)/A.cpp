#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,s1;
    cin>> s;
    for(int i=0; i < s.size(); i++){
        if(tolower(s[i])!= 'a' && tolower(s[i])!= 'e' && tolower(s[i])!= 'i' && tolower(s[i])!= 'o' && tolower(s[i])!= 'u' && tolower(s[i]) != 'y'){
            s1.push_back('.');
            s1.push_back(tolower(s[i]));
        }
    }
    cout<< s1;
}
