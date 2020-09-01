#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n;
    while(cin >> s >> n){
        string ans;
        int cnt = 0, k = s.size(), l = 0;
        for(auto &i : s){
            if(isalpha(i))cnt++;
        }
        if(cnt > n){
            for(int i = 0; i < k - 1; i++){
                if(cnt == n){
                    l = i;
                    break;
                }
                if(s[i+1] == '?' || s[i+1] == '*'){
                    cnt--;
                }else if(s[i] != '?' && s[i] != '*'){
                    ans += s[i];
                }
            } 
        } else if(cnt < n){
            bool flag = 0;
            for(int i = 0; i < k - 1; i++){
                if(flag)break;
                if(s[i+1] == '?'){
                    ans += s[i];
                    continue;
                }
                else if(s[i+1] == '*'){
                    flag = 1;
                    l = i;
                    while(cnt < n){
                        ans += s[i];
                        cnt++;
                    }
                }else if(s[i] != '?' && s[i] != '*'){
                    ans += s[i];
                }
            }
        }
        if(ans.size() < n){
            for(int i = l; i < k; i++){
                if(isalpha(s[i]))ans += s[i];
            }   
        }
        if(cnt == n)cout << ans << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}