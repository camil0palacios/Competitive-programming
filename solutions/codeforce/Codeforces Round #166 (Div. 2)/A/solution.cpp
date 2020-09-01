#include <bits/stdc++.h>
using namespace std;

bool cmp(int n){
    string a = to_string(n);
    set<char> s;
    for(auto & i : a){
        if(s.count(i))return true;
        else s.insert(i);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        n++;
        while(cmp(n)){
            n++;
        }
        cout << n << endl;
    }
    return 0;
}