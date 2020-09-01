#include <bits/stdc++.h>
using namespace std;

map<char,vector<char>> adj;
set<char> visited;
int total;

void dfs(char n){

    visited.insert(n);
    total++;
    for(auto i: adj[n]){
        if(visited.find(i) == visited.end())dfs(i);
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    string s;
    cin>>n;
    cin.ignore();
    while(n--){

        adj.clear();
        visited.clear();
        while(getline(cin,s) && s[0] != '*'){
            adj[s[1]].emplace_back(s[3]);
            adj[s[3]].emplace_back(s[1]);
        }
        getline(cin,s);
        int trees = 0, acorn = 0;
        for(int i = 0; i < s.size(); i+=2){
            total = 0;
            if(visited.find(s[i]) == visited.end())
                dfs(s[i]);
            if(total > 1)trees++;
            else if(total == 1)acorn++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
    }

    return 0;
}
