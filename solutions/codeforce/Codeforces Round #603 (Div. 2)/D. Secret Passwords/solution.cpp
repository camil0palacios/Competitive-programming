#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 2e5 + 5;
string a[MXN];
int p[26], cnt[26];

int find(int a){ return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) { a = find(a), b = find(b); if(a != b) p[b] = a; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 26; i++)
        p[i] = i;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(j) join(a[i][j]-'a', a[i][j - 1]-'a');
            cnt[a[i][j]-'a']++;
        }
    }
    set<int> s;
    for(int i = 0; i < 26; i++) {
        if(cnt[i]) 
            s.insert(find(i));
    } 
    cout << s.size() << endl;
    return 0;
}