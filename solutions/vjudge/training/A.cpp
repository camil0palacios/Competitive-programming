#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    set<string> roots;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        string ns;
        bool a[26];
        memset(a, 0, sizeof a);
        for(int j = 0; j < (int)s.size(); j++){
            if(!a[s[j]-'a']){
                ns += s[j];
                a[s[j] -'a'] = 1;
            }
        }
        sort(ns.begin(), ns.end());
        roots.insert(ns);
    }
    cout << roots.size() << endl;
    return 0;
}