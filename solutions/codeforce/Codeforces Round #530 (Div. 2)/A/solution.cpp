#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int w, h, u1, h1, u2, h2;
    cin >> w >> h;
    cin >> u1 >> h1;
    cin >> u2 >> h2;
    h++;
    while(h--){
        w += h;
        if(h == h1)w -= u1;
        if(h == h2)w -= u2;
        if(w < 0)w = 0;
    }
    cout << w << endl;
    return 0;
}