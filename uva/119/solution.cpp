#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    int n;
    bool flag = false;
    while(cin >> n){
        map<string, int> m;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            m[v[i]] = 0;
        }
        for(int i = 0; i < n; i++){
            string a;
            int x, y;
            cin >> a >> x >> y;
            if(y > 0){
                int val = x/y;
                for(int j = 0; j < y; j++){
                    string b;
                    cin >> b;
                    m[b] += val;
                }
                m[a] -= (val*y);
            }
        }
        if(flag)cout << endl;
        for(int i = 0; i < n; i++){
            cout << v[i] << " " << m[v[i]] << endl;
        }
        flag = true;
    }
    return 0;
}