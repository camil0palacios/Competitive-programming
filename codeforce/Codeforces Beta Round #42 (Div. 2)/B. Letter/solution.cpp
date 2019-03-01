#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);
        map<char, int> m1, m2;
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] != ' '){
                if(m1.count(s2[i]))m1[s2[i]]++;
                else m1[s2[i]] = 1;
            }
        }
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != ' '){
                if(m1.count(s1[i])){
                    if(m2.count(s1[i]) == 0){
                        m2[s1[i]] = 1;
                    }
                    else if(m2[s1[i]] < m1[s1[i]]){
                        m2[s1[i]]++;
                    }
                }
            }
        }
        if(m1.size() == m2.size()){
            auto i = m1.begin();
            auto j = m2.begin();
            bool b = 1;
            for(int k = 0; k < m1.size(); k++){
                if(i -> second != j -> second){
                    b = 0;
                }
                i++; j++;
            }
            if(b)cout << "YES" << endl;
            else cout << "NO" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}