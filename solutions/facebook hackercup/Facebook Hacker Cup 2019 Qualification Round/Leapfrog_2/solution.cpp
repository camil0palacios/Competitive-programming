#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    for(int j = 1; j <= t; j++){
        cin >> s;
        int bet = 0;
        for(int i = 1; i < (int)s.size(); i++){
            bet += (s[i] == 'B');
        }
        cout << "Case #" << j << ": ";
        if((bet >= 2 && bet < s.size()-1) || (bet == 1 && s.size() == 3)){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}