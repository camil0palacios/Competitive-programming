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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    string s;
    cin >> n >> q >> s;
    ll p[n+1][26];
    memset(p, 0, sizeof p);
    fori(i,0,n) {
        fori(j,0,26) p[i+1][j] += p[i][j];
        p[i+1][s[i]-'a']++;
    }
    fori(i,0,q) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        fori(j,0,26) ans += (p[r][j] - p[l-1][j])*(j+1); 
        cout << ans << endl;   
    }
    return 0;
}