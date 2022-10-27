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

const int oo = 1e9;
const int Mxc =  26;
int g[Mxc][Mxc];

void floyd() {
    fori(k,0,Mxc) fori(i,0,Mxc) fori(j,0,Mxc) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
}

int solve() {
    string s; int k;
    cin >> s >> k;
    int n = sz(s);
    fori(i,0,Mxc) fori(j,0,Mxc) {
        if(i == j) g[i][i] = 0;
        else g[i][j] = oo; 
    }
    fori(i,0,k) {
        string e; cin >> e;
        int u = e[0]-'A';
        int v = e[1]-'A';
        g[u][v] = 1;
    }
    floyd();
    // cout << g[1][0] << endl;
    int ans = oo;
    fori(i,0,26) {
        int ok = 1, tmp = 0;
        fori(j,0,n) {
            int c = s[j]-'A';
            if(c == i) continue;
            if(g[c][i] != oo) tmp += g[c][i];
            else { ok = 0; break; }
        }
        if(ok) ans = min(ans, tmp);
    }
    return ans == oo ? -1 : ans;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fore(i,1,t) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0; 
}