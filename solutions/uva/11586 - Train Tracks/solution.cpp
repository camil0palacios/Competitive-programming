#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        int cont = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'M')cont++;
            else if(s[i] == 'F')cont--;
        }

        if(cont == 0 && s.size() > 3)cout << "LOOP" << endl;
        else cout << "NO LOOP" << endl;
    }

    return 0;
}