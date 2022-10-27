#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

struct Node {
    map<char, Node> m;
    int size_node = 0;
    void add(int i, string & s) {
        size_node++;
        if(i == sz(s)) return;
        m[s[i]].add(i+1, s);
    }
    int dfs(int i, string & s) {
        if(i == sz(s)) return size_node-1;
        return m[s[i]].dfs(i+1, s);
    }
};

const int Mxn = 2e5 + 5;
string s[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    Node r;
    fori(i,0,n) {
        cin >> s[i];
        r.add(0, s[i]);
    }
    int ans = 0;
    fori(i,0,n) {
        ans += r.dfs(0, s[i]);
    }
    cout << ans << endl;
    return 0; 
}