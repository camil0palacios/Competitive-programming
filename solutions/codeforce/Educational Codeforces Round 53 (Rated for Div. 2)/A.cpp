#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j + i <= n; j++){
            vector<int> v(26,0);
            bool ans = true;
            for(int k = j; k < j + i; k++){
                v[s[k] - 'a']++;
                if(v[s[k] - 'a'] > i/2){
                    ans = false;
                    break;
                }
            }
            if(!ans)continue;
            cout << "YES" << endl;
            for(int k = j ; k < j + i; k++)cout << s[k];
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}