#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(s.size() > 10){
                int x = s.size(), ab = 0;
                cout << s[0];
                for(int j = 1; j < x - 1; j++)ab++;
                cout << ab << s[x-1] << endl;
            }else cout << s << endl;
        }
    }
    return 0;
}
