#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        string s;
        cin >> s;
        char cur = s[0];
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(cur != s[i]){
                ans++;
                cur = s[i];
            }
        }
        if(cur == '-')ans++;
        cout << "Case #" << cs << ": " <<  ans << endl; 
    }
    return 0;
}