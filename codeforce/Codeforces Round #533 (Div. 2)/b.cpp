#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    while(cin >> n >> k){
        string s; 
        cin >> s;
        int v[26], x = 0, i = 0;
        memset(v, 0, sizeof v);
        while(i < (int)s.size()){
            char c = s[i];
            int j = 0;
            while(s[i] == c && j < k){
                i++;
                j++;
            }
            if(j == k)v[c - 'a']++;
        }
        for(int i = 0; i < 26; i++)
            x = max(x, v[i]);
        cout << x << endl;
    }
    return 0;
}