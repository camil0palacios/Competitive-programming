#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("blist.in","r",stdin);
    freopen("blist.out","w",stdout);

    int n;
    cin >> n;
    map<int, int> s, t;
    int x = 1001, y = 0;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        s[a] = t[b] = c;
        x = min(x, a);
        y = max(y, b);
    }
    int u = 0, ans = 0;
    for(int i = x; i <= y; i++){
        if(s.count(i)){
            u += s[i];
            ans = max(ans, u);
        }
        else if(t.count(i)){
            u -= t[i];
        }
    }

    cout << ans << endl;

    return 0;
}