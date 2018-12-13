#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, c = 1;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        vector<int> v(100, 0);
        int i = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '<')i--;
            else if(s[j] == '>')i++;
            else if(s[j] == '+'){
                v[i]++;
                if(v[i] == 256)v[i] = 0;
            }
            else if(s[j] == '-'){
                v[i]--;
                if(v[i] < 0)v[i] = 255;
            }
            if(i < 0)i = 99;
            if(i > 99)i = 0;
        }
        cout << "Case " << c++ << ": ";
        for(int j = 0; j < 100; j++){
            printf("%02X", v[j]);
            if(j != 99)cout << " ";
            else cout << endl;
        }
    }
    return 0;
}