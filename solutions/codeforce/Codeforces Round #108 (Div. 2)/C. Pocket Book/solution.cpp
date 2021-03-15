#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int mod = 1e9 + 7;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<int> s[m];
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for(int j = 0; j < m; j++) {
            s[j].insert(t[j]-'0');
        }
    } 
    ll ans = 1;
    for(int i = 0; i < m; i++) {
        ans = (ans * s[i].size()) % mod;
    }
    cout << ans << endl;
    return 0; 
}