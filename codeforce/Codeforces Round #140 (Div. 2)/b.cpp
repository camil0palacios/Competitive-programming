#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    while(cin >> n){
        vector<int> v(n);
        vector<int> inc(n,0);
        vector<int> noinc(n,0);
        for(auto & i : v)cin >> i, i--;
        for(int i = 0; i < n; i++){
            if(!inc[v[i]])inc[v[i]] = i + 1;
        }
        int aux = 1;
        long long vas = 0, pet = 0;
        for(int i = n - 1; i >= 0; i--, aux++){
            if(!noinc[v[i]])noinc[v[i]] = aux;
        }
        cin >> q;
        while(q--){
            cin >> aux;
            vas += inc[aux-1]*1LL;
            pet += noinc[aux-1]*1LL;
        }
        cout << vas << " " << pet << endl;
        
    }
    return 0;
}