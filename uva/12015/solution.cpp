#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, caseNum = 1;
    cin >> n;
    while(n--){
        map<int,vector<string>> m;
        int mmax = 0;
        for(int i = 0; i < 10; i++){
            string s; cin >> s;
            int j; cin >> j;
            m[j].emplace_back(s);
            mmax = max(mmax, j);
        }
        cout << "Case #" << caseNum++ << ":" << endl;
        for(auto i : m[mmax])
            cout << i << endl;
    }
    return 0;
}