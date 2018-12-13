#include <bits/stdc++.h>
using namespace std;

struct trie{
    map<char,trie> m;
    bool isend;

    trie(): isend(false), m(){}
    void add(int idx, string &s){
        if(idx < s.size()) m[s[idx]].add(idx + 1, s);
        else isend = true;
    }

    long long dfs(int n, long long acc = 0){
        if(isend)return 1LL << (n - acc);
        long long sum = 0;
        for(auto i: m){
            sum += i.second.dfs(n, acc + 1);
        }
        return sum;
    }
};


int main(){
    long long ans = 0;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long n, p;
        cin >> n >> p;
        trie t;
        for(long long i = 0; i < p; i++){
            string s; cin >> s;
            t.m[s[0]].add(1,s);
        }
        long long ans = 1LL << n;
        ans -= t.dfs(n);
        cout << "Case #" << i+1 << ": " << ans << endl;

    }
    return 0;
}