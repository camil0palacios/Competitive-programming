#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        int p = 0;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            if(s == "LEFT")p--, v[i] = -1;
            else if(s == "RIGHT")p++, v[i] = 1;
            else{
                int tmp;
                cin >> s >> tmp;
                p += v[tmp-1];
                v[i] = v[tmp-1];
            }
        }
        cout << p << endl;
    }
    return 0;
}