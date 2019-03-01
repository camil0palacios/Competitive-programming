#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    long long t, x1, y1, x2, y2;
    while(cin >> t >> x1 >> y1 >> x2 >> y2){
        int ans = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++){
            if(x1 < x2 && s[i] == 'E'){
                x1++;
                ans = i;
            }
            else if(x1 > x2 && s[i] == 'W'){
                x1--;
                ans =i;
            }
            if(y1 < y2 && s[i] == 'N'){
                y1++;
                ans = i;
            }
            else if(y1 > y2 && s[i] == 'S'){
                y2++;
                ans = i;
            }
        }
        if(x1 == x2 && y1 == y2)cout << ans + 1  << endl;
        else cout << -1 << endl;
    }
    return 0;
}