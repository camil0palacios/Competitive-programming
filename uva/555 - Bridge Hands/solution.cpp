#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void print(vector<string> & v){
    for(int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << endl;
}

void fill(string &s, int &turn, vector<vector<string>> &v){
    for(int i = 0; i < s.size(); i += 2){
        if(turn > 3)turn = 0;
        v[turn++].emplace_back(s.substr(i, 2));
    }
}

map<char, int> suit = {{'C',0},{'D',1},{'S',2},{'H', 3}};
map<char, int> ranking = {
    {'2',0},{'3',1},{'4',2},{'5',3},{'6',4},{'7',5},{'8',6},{'9',7},
    {'T',8},{'J',9},{'Q',10},{'K',11},{'A',12}
    };

void solve(){
    string s;
    while(cin >> s && s != "#"){
        map<char, int> deal = {{'S', 0},{'W', 1}, {'N', 2}, {'E', 3}};
        vector<vector<string>> p(4, vector<string>(0)); // S, W, N, E
        int turn = deal[s[0]] + 1;
        cin >> s;
        fill(s, turn, p);
        cin >> s;
        fill(s, turn, p);
        for(int i = 0; i < 4; i++){ 
            sort(p[i].begin(), p[i].end(), [](const string & a,const string & b){
                if(suit[a[0]] != suit[b[0]])return suit[a[0]] < suit[b[0]];
                return ranking[a[1]] < ranking[b[1]];
            });
        }
        s = "SWNE";
        for(int i = 0; i < s.size(); i++){
            cout << s[i] << ':';
            print(p[i]);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}