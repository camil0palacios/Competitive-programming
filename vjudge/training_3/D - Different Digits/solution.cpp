#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        int ans = 0;
        for(int i = n; i <= m; i++){
            string s = to_string(i);
            set<char> con;
            for(int j = 0; j < s.size(); j++){
                con.insert(s[j]);
            }
            if(con.size() == s.size())ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
