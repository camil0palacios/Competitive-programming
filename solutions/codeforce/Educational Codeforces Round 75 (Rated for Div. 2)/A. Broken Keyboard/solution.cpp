#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool vis[27];
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < s.size(); i++){
            if(!vis[s[i] - 'a']){
                int cnt = 0;
                char tmp = s[i];
                while(i < s.size() && tmp == s[i]){
                    i++, cnt++;
                }
                i--;
                if(cnt & 1)vis[tmp - 'a'] = 1;
            }
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(vis[c - 'a']){
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}