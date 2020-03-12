#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 1e6 + 5;

struct HashTable{
    int h[MAXN];
    void add(string & s){
        h[hash(s)]++;
    }
    bool find(string & s){
        int hash_val = hash(s);
        if(h[hash_val]--)return 1;
        return 0;
    }
    int hash(string & s){
        const int p = 59;
        const int m = 104723;
        long long hash_val = 0;
        long long p_pow = 1;
        for(int i = 0; i < s.size(); i++){
            hash_val = (hash_val + (s[i] - 'a' + 1)*p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_val;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    HashTable h;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        h.add(s);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        ans += h.find(s);
    }
    cout << (ans == m ? "Yes" : "No") << endl;
    return 0;
}