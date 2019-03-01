#include <bits/stdc++.h>
using namespace std;

void criba(vector<bool> & v){
    v[0] = v[1] = 0;
    for(int i = 2; i < v.size(); i++){
        if(v[i])
            for(int j = 2; i*j < v.size(); j++)
                v[i*j] = 0;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    vector<bool> v(100,1);
    criba(v);
    while(cin >> n >> m){
        int i;
        for(i = n + 1; i < 100 && !v[i]; i++){}
        if(i == m)cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
    return 0;
}