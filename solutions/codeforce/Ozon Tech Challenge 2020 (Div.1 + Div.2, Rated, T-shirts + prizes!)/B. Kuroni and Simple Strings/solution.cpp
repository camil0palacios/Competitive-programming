#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1;
    vector<bool> ok(s.size());
    int ans = 0;
    while(i < j){
        if(s[i] == ')')i++;
        else if(s[j] == '(')j--;
        else {
            ans += 2;
            ok[i] = ok[j] = 1;
            j--, i++;
        }
    }
    if(ans){
        cout << 1 << endl;
        cout << ans << endl;
        for(int i = 0; i < ok.size(); i++){
            if(ok[i])cout << i + 1 << ' '; 
        }
    }else cout << 0 << endl;
    cout << endl;
    return 0;
}