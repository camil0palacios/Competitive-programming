#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s;

bool check(int idx, char c){
    if(c == 'D' && s.substr(idx,5) == "Danil"){
        return 1;
    }
    if(c == 'O' && s.substr(idx,4) == "Olya"){
        return 1;
    }
    if(c == 'S' && s.substr(idx, 5) == "Slava"){
        return 1;
    }
    if(c == 'A' && s.substr(idx, 3) == "Ann"){
        return 1;
    }
    if(c == 'N' && s.substr(idx, 6) == "Nikita"){
        return 1;
    }
    return 0;
}

int main(){
    cin >> s;
    int n = (int)s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D' || s[i] == 'O' || s[i] == 'S' || 
        s[i] == 'A' || s[i] == 'N'){
            if(check(i,s[i])){
                ans++;
            }
        }
    }
    cout << (ans == 1 ? "YES" : "NO") << endl;
    return 0;
}