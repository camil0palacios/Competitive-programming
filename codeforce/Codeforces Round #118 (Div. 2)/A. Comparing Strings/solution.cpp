#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b){
        int f = 1;
        if(a.size() == b.size()){
            int cnt = 0;
            set<char> aa, bb;
            for(int i = 0; i < a.size(); i++){
                if(a[i] == b[i])cnt++;
                aa.insert(a[i]);
                bb.insert(b[i]);
            }
            if(aa.size() == bb.size() && (cnt == a.size() || cnt == a.size() - 2)){
                int n = aa.size();
                bool f = 1;
                auto it1 = aa.begin(), it2 = bb.begin();
                for(int i = 0; i < n; i++){
                    if(*it1 != *it2)f = 0;
                    ++it1; ++it2;
                }
                if(f)cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else 
                cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}