#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> v(n);
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin ,s);
        v[i] = s;
    }
    set<string> ans;
    for(int i = 0; i < n; i++){
        bool plus = false;
        int k = 0;
        string s;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == '+')plus = true;
            if(v[i][j] == '@'){
                k = j;
                break;
            }
            if(!plus && v[i][j] != '.'){
                s += v[i][j];
            }
        }
        for(int j = k; j < v[i].size(); j++)
            s += v[i][j];

        if(!ans.count(s))ans.insert(s);
    }
    cout << ans.size() << endl;
    return 0;
}