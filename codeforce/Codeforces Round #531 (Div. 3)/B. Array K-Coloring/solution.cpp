#include <bits/stdc++.h>
using namespace std;

int main(){

    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, a;
    while(cin >> n >> k){
        set<int> c[k];
        int v[n];
        bool flag = 1;
        for(int i = 0; i < n; i++){
            cin >> a;
            bool aux = 0;
            if(!c[i%k].count(a)){
                aux = 1;
                c[i%k].insert(a);
                v[i] = i%k;
            }else{
                for(int j = 0; j < k; j++){
                    if(!c[j].count(a)){
                        aux = 1;
                        c[j].insert(a);
                        v[i] = j;
                    }
                    if(aux)break;
                }
            }
            if(!aux)flag = 0;
        }
        if(flag){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++)
                cout << v[i] + 1 << " ";
            cout << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}