#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long reduce;
vector<int> v;

struct trie{
    map<char,trie> n;
    bool begin;
    trie(bool _begin = false): n(), begin(_begin){}

    void add(string &s, int idx = 0){
        if(idx < s.size()){
            n[s[idx]].add(s, idx + 1);
        }
    }

    void add_rev(string &s, int idx){
        if(idx >= 0){
            n[s[idx]].add_rev(s, idx - 1);
        }
    }

    int dfs_pref(){
        int tam = 1;
        for(auto &i : n){
            if(!begin)reduce += v[i.first - 'a'];
            tam += i.second.dfs_pref();
        }
        return tam;
    }

    int dfs_suf(){
        int tam = 1;
        for(auto &i : n){
            if(!begin)v[i.first - 'a']++;
            tam += i.second.dfs_suf();
        }
        return tam;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n, m){
        cin.ignore();
        trie t1(true), t2(true);
        string s;
        reduce = 0;
        for(int i = 0; i < n; i++){
            getline(cin, s);
            t1.add(s);
        }
        for(int i = 0; i < m; i++){
            getline(cin, s);
            t2.add_rev(s, s.size() - 1);
        }
        v.assign(26,0);
        long long ans = 0, tam1 = 0, tam2 = 0;
        tam1 = t2.dfs_suf()-1;
        tam2 = t1.dfs_pref()-1;
        ans = tam1 * tam2;
        //cout << ans << " " << reduce << endl;
        cout << ans - reduce << endl;
    }
    return 0;
}