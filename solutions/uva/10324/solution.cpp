#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int c = 1;
    while(cin >> s){
        cout << "Case " << c++ << ':' << endl;
        int n;
        cin >> n;
        while(n--){
            int j, l, r;
            bool flag = true;
            cin >> l >> r;
            j = max(l,r);
            for(int i = min(l,r); i < j; i++){
                if(s[i] != s[i+1])
                    flag = false;
            }
            if(flag)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}