#include <bits/stdc++.h>
using namespace std;

map<string, int> k;

void solve(){
    string s;
    cin >> s >> s;
    k.clear();
    for(int i = 0; i < s.size()-2; i++){
        k[s.substr(i,3)]++;
    }
    cout << k["TTT"] << " ";
    cout << k["TTH"] << " ";
    cout << k["THT"] << " ";
    cout << k["THH"] << " ";
    cout << k["HTT"] << " ";
    cout << k["HTH"] << " ";
    cout << k["HHT"] << " ";
    cout << k["HHH"] << endl; 
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << i << " ";
        solve();
    }
    return 0;
}