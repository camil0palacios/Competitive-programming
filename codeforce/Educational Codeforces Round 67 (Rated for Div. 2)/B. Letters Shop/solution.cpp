#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, ts;
    cin >> s >> s;
    cin >> n;
    map<char,vector<int>> m;
    for(int i = 0; i < s.size(); i++){
        m[s[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        cin >> ts;
        int idx[27];
        memset(idx, 0, sizeof idx);
        int mmax = 0;
        for(int j = 0; j < ts.size(); j++){
            mmax = max(mmax, m[ts[j]][idx[ts[j]-'a']]);
            idx[ts[j]-'a']++;
        }
        cout << mmax + 1 << endl;
        
    }
    return 0;
}