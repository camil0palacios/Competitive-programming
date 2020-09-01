#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n, m){
        int v[n];
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        while(m--){
            int a, b, c;
            cin >> a >> b >> c; a--; b--;
            v[b] += c;
            v[a] -= c;
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(v[i] < 0)flag = false;
        }

        if(flag)cout << "S" << endl;
        else cout << "N" << endl;
    }
    return 0;
}