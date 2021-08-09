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
typedef pair<ll,ll> pll;

const long long base = 1777771;
const long long mod1 = 999727999;
const long long mod2 = 1070777777;

struct Hash {
	vector<pll> hs, pot;
	Hash(vi & s) {
		hs.resize(SZ(s) + 1); pot.resize(SZ(s) + 1);
		pot[0] = pll(1, 1);
		for (int i = 1; i <= SZ(s); i++) {
			hs[i].ft = (hs[i - 1].ft * base + s[i - 1]) % mod1;
			hs[i].sd = (hs[i - 1].sd * base + s[i - 1]) % mod2;
			pot[i].ft = (pot[i - 1].ft * base) % mod1;
			pot[i].sd = (pot[i - 1].sd * base) % mod2;
		}
	}
    Hash(vector<pll> & s) {
		hs.resize(SZ(s) + 1); pot.resize(SZ(s) + 1);
		pot[0] = pll(1, 1);
		for (int i = 1; i <= SZ(s); i++) {
			hs[i].ft = (hs[i - 1].ft * base + (s[i - 1].ft + s[i - 1].sd) % mod1 ) % mod1;
			hs[i].sd = (hs[i - 1].sd * base + (s[i - 1].ft + s[i - 1].sd) % mod2 ) % mod2;
			pot[i].ft = (pot[i - 1].ft * base) % mod1;
			pot[i].sd = (pot[i - 1].sd * base) % mod2;
		}
	}
	pll get(int l, int r) { l++; r++;
		long long x1 = hs[r].ft;
		long long y1 = (hs[l - 1].ft * pot[r - l + 1].ft) % mod1;
		long long x2 = hs[r].sd;
		long long y2 = (hs[l - 1].sd * pot[r - l + 1].sd) % mod2;
		return pll((x1 - y1 + mod1) % mod1, (x2 - y2 + mod2) % mod2);
	}
};

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<vi> a;
    string s;
    while(cin >> s) {
        vi tmp;
        fori(i,0,sz(s)) tmp.eb(s[i]-'a');
        a.eb(tmp);
    }
    int n = sz(a);
    fori(i,0,n) a.eb(a[i]);
    int m = sz(a);
    fori(i,0,m) fori(j,0,n) a[i].eb(a[i][j]);
    vector<vector<pll>> h(m, vector<pll>(m));
    fori(i,0,m) {
        Hash x(a[i]);
        h[i] = x.hs;
    }
    fori(i,0,n) {
        
    }
    return 0; 
}