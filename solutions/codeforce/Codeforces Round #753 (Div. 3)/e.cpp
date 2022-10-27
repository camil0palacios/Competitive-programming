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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

map<char, ii> to({{'L', mp(-1, 0)}, {'R', mp(1, 0)}, {'U', mp(0, -1)}, {'D', mp(0, 1)}}); 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        int u = 0, d = 0, l = 0, r = 0;
        int x = 0, y = 0, sx = 0, sy = 0;
        fori(i,0,sz(s)) {
            x += to[s[i]].sd;
            y += to[s[i]].ft;
            u = min(u, x);
            d = max(d, x);
            l = min(l, y);
            r = max(r, y);
            if(abs(u - d) >= n || abs(l - r) >= m) break;
            sx = abs(u), sy = abs(l);  
        }   
        cout << sx+1 << ' ' << sy+1 << endl;
    }
    return 0; 
}