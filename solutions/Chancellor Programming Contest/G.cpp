#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string name, phrase, c;
        getline(cin, name);
        getline(cin, c);
        getline(cin, phrase);

        int flag = false;
        if(c == "Y"){
            cout << 'Y' << endl;
            continue;
        }
        set<char> s;
        for(int i = 0; i < name.size(); i++){
            char cc  = tolower(name[i]);
            if(cc == 'g' || cc == 'e'|| cc == 'r' || cc == 's' || cc == 'o' || cc == 'n'){
                s.insert(cc);
            }
            if(s.size() == 6){
                cout << 'Y' << endl;
                flag = true;
                break;
            }
        }
        if(flag)continue;
        s.clear();
        for(int i = 0; i < phrase.size(); i++){
            char cc = tolower(phrase[i]);
            if(cc == 't' || cc == 'r' || cc == 'i' || cc == 'h'){
                s.insert(cc);
            }
            if(s.size() == 4){
                cout << 'Y' << endl;
                flag = true;
                break;
            }
        }
        if(!flag)cout << 'N' << endl;
    }
    return 0;
}