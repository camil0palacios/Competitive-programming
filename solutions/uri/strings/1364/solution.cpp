#include <bits/stdc++.h>
#define endl '\n'
#define mp make_pair
using namespace std;

struct nodo{
    map<char,nodo*> n;
    bool isend;
    nodo(): n(), isend(false){}
};

class trie{
    private: 
        nodo* root;
        size_t size;
        
        nodo* insert(nodo* a, string &s, int idx){
            if(!a)a = new nodo();
            if(idx == s.size()){
                a -> isend = true;
                return a;
            }
            if(!(a -> n.count(s[idx]))){
                a -> n.insert(mp(s[idx], nullptr));
                size++;
            }
            a -> n[s[idx]] = insert(a -> n[s[idx]], s, idx + 1);
            return a;
        }

        bool search(nodo* a, string &s, int idx){
            if(a -> isend)return true;
            if(idx == s.size())return a -> isend;
            if(!(a -> n.count(s[idx])))return false;
            bool ans = search(a -> n[s[idx]], s, idx + 1);
            if(ans)s[idx] = ' ';
            return ans;
        }

        void print(nodo *a){
            
            if(!a)return;
            for(auto i: (a -> n)){
                cout << i.first << endl;
                print(i.second);
            }
        }

    public:
        trie():root(NULL), size(0){}

        void insert(string &s){
            root = insert(root, s, 0);
        }

        bool search(string &s, int idx){
            return search(root, s, idx);
        }

        void print(){
            print(root);
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n, m){
        cin.ignore();
        trie t;
        string s;
        for(int i = 0; i < n; i++){
            getline(cin, s);
            t.insert(s);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            getline(cin, s);
            for(int j = s.size()-1; j >= 0; j--){
                if(t.search(s, j)){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}