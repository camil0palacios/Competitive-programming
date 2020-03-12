#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int lvl = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U')lvl++;
        if(s[i] == 'D'){
            lvl--;
            if(lvl == -1)ans++;
        }
    }
    cout << ans << endl;
    return 0;
}