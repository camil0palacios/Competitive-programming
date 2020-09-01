#include <bits/stdc++.h>
using namespace std;

int fun(string & s, int i, int j){
    if(j == s.size()){
        if(s[i] == 'R')return 'B';
        if(s[i] == 'G')return 'R';
        if(s[i] == 'B')return 'R';
    }
    if(s[i] == 'R' && s[j] == 'B')return 'G';
    if(s[i] == 'R' && s[j] == 'G')return 'B';
    if(s[i] == 'B' && s[j] == 'G')return 'R';
    if(s[i] == 'B' && s[j] == 'R')return 'G';
    if(s[i] == 'G' && s[j] == 'B')return 'R';
    if(s[i] == 'G' && s[j] == 'R')return 'B';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        string s, ns;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(s[i] == s[j]){
                j++;
            }
            int ch = (j-i) >> 1;
            char c = fun(s, i, j);
            for(int k = i + 1, aux = 0; k < j && aux < ch; k+=2){
                aux++;
                ans++;
                s[k] = c;
            }
            i = j - 1;
        }
        cout << ans << endl << s << endl;
    }
    return 0;
}