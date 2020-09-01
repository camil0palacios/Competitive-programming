#include <bits/stdc++.h>
using namespace std;

map<string,int> m;

void solve(){
    int mon[2], d[2], y[2];
    char s[26];
    for(int i = 0; i < 2; i++){
        scanf("%s %d, %d", &s, &d[i], &y[i]);
        mon[i] = m[s];
    }
    int ans = ((y[1]-1)/4 - (y[1]-1)/100 + (y[1]-1)/400) - ((y[0]-1)/4 - (y[0]-1)/100 + (y[0]-1)/400);
    if(((y[0] % 4 == 0 && y[0] % 100) || (y[0] % 400 == 0)) && mon[0] > 2){
        ans--;
    }
    if(((y[1] % 4 == 0 && y[1] % 100) || (y[1] % 400 == 0)) && (mon[1] > 2 || (mon[1] == 2 && d[1] == 29))){
        ans++;
    }
    cout << ans << endl;
}

int main(){
    m["January"] = 1, m["February"] = 2, m["March"] = 3, m["April"] = 4, m["May"] = 5, m["June"] = 6;
    m["July"] = 7, m["August"] = 8, m["September"] = 9, m["October"] = 10, m["November"] = 11;
    m["December"] = 12;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}