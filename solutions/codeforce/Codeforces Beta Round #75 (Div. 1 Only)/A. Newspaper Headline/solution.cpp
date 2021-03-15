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

const int Mxn = 1e4 + 5;
vi g[26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    int n = sz(a), m = sz(b);
    fori(i,0,n) g[a[i]-'a'].eb(i);
    int ans = 1, j = -1;
    fori(i,0,m) {
        if(sz(g[b[i]-'a']) == 0) { cout << -1 << endl; return 0; }
        auto it = upper_bound(all(g[b[i]-'a']), j);
        if(it == g[b[i]-'a'].end()) j = -1, ans++;
        j = *upper_bound(all(g[b[i]-'a']), j);
    }
    cout << ans << endl;
    return 0; 
}