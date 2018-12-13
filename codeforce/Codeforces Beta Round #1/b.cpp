#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        bool flag = true;
        int x = 0;
        if(s[0] == 'R' && s[1] >= '0' && s[1] <= '9'){
            for(int i = 0; i < s.size(); i++)
                if(s[i] == 'C'){
                    x = i;
                    flag = false;
                }
        }
        if(flag){
            long long ans = 0;
            cout << 'R';
            for(int i = 0; i < s.size(); i++){
                if(s[i] >= 'A' && s[i] <= 'Z')ans = ans*26 + (s[i] - 'A' + 1);
                else cout << s[i];
            }
            cout << 'C' << ans << endl;
        }else{
            long long row = stoll(s.substr(1,x-1));
            long long col = stoll(s.substr(x+1, s.size() - 1));
            string tmp;
            while(col){
                long long mod = col % 26LL;
                if(mod){
                    tmp += mod + 'A' - 1;
                }
                else {
                    tmp += 'Z';
                    mod++;
                }
                col -= mod;
                col /= 26;
            }

            for(int i = tmp.size() - 1; i >= 0; i--)
                cout << tmp[i];
            cout << row << endl;
        }
    }
    return 0;
}