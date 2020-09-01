#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, n;
    string s;
    cin >> q;
    while(q--){
        cin >> n >> s;
        if(n == 2){
            int x = s[0] - '0';
            int y = s[1] - '0';
            if(x < y){
                cout << "YES" << endl << 2 << endl;
                cout << s[0] << " " << s[1] << endl;
            }
            else cout << "NO" << endl;
        }else{
            cout << "YES" << endl << 2 << endl;
            cout << s[0] << " ";
            for(int i = 1; i < n; i++){
                cout << s[i];
            }
            cout << endl;
        }
        
    }
    return 0;
}