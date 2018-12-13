#include <bits/stdc++.h>
#define end '\n'
#define mp make_pair
using namespace std;

struct trie{
    map<char,trie> n;
    int frec;
    trie():frec(0){}
    void add(string &s, int idx){
        frec++;
        if(idx < s.size())n[s[idx]].add(s, idx + 1);
    }
    long long search(string &s, int idx){
        long long ans = 0;
        if(frec > 0){
            ans++;
            frec--;
        }
        if(!(s.size() > idx && n.count(s[idx])))return ans;
        return n[s[idx]].search(s, idx + 1) + ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n && n != -1){
        trie t;
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            t.frec++;
            t.n[s[0]].add(s,1);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            mapa.insert(s);
            if(t.n.count(s[0])){
                ans += t.n[s[0]].search(s,1);
            }
        }

        cout << ans << endl;
    }
    return 0;
}