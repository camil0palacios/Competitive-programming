#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n, n){
        cin >> m;
        set<string> s;
        for(int i = 0; i < n; i++){
            string tmp; cin >> tmp;
            s.insert(tmp);
        }
        bool flag = 1;
        while(m--){
            int x, cont = 0;
            cin >> n >> x;
            for(int i = 0; i < n; i++){
                string tmp; cin >> tmp;
                if(s.count(tmp))cont++;
            }
            if(cont < x)flag = 0;
        }

        if(flag)cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}