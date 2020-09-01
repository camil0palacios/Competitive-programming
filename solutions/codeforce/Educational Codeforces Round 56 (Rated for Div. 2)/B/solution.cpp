#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        map<char, int> m;
        for(auto &i : s){
            if(m.count(i))m[i]++;
            else m[i] = 1;
        }
        if(m.size() == 1)cout << -1 << endl;
        else{
            for(auto &i : m){
                for(int j = 0; j < i.second; j++){
                    cout << i.first;
                }
            }
            cout << endl;
        }
    }

    return 0;
}