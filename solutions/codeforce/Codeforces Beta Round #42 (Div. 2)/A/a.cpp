#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while(cin >> n){
        map<string,int> m;
        string ans, tmp;
        int mmax = 1;
        cin >> tmp;
        ans = tmp;
        m[tmp] = 1;
        while(--n){
            cin >> tmp;
            if(m.count(tmp)){
                m[tmp]++;
                int aux = m[tmp];
                if(mmax < aux){
                    mmax = aux;
                    ans = tmp;
                }
            }
            else m[tmp] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}