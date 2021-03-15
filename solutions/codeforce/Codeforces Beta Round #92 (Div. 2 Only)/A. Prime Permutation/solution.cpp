#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1010;
int p[MXN];
int pf[26];
vector<int> v[MXN];
bool sieve[MXN];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) { p[find(b)] = p[find(a)]; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = (int) s.size();
    for(int i = 0; i <= n; i++) p[i] = i;
    memset(sieve, -1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(sieve[i]) {
            for(int j = i*2; j <= n; j += i) {
                sieve[j] = 0;
                join(i, j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        pf[s[i]-'a']++;
    }
    priority_queue<pair<int,char>> q;
    for(int i = 0; i < 26; i++) {
        if(pf[i]) q.push({pf[i], char(i + 'a')});
    }
    set<int> cnt;
    for(int i = 1; i <= n; i++) {
        v[find(i)].emplace_back(i);
        cnt.insert(find(i));
    }
    sort(v, v + n + 1, [&](auto & a, auto & b){
        return a.size() > b.size();
    }); 
    string ans = string(n, 'a');
    for(int i = 0; i < cnt.size(); i++) {
        int x = q.top().first;
        char c = q.top().second;
        if(x < v[i].size()) {
            cout << "NO" << endl;
            return 0;
        }
        int r = x - v[i].size();
        for(auto & j : v[i]) {
            ans[j-1] = c;
        }
        q.pop();
        if(r) q.push({r, c});
    }
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
}