#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    while(cin >> n >> s, n){
        int l = -1, r = -1, ans = 2000001;
        for(int i = 0; i < n; i++){
            if(s[i] == 'Z'){
                ans = 0;
                break;
            }
            if(s[i] == 'R')l = i;
            if(s[i] == 'D')r = i;
            if(l != -1 && r != -1)
                ans = min(ans, abs(l-r));
        }
        cout << ans << endl;
    }
    return 0;
}