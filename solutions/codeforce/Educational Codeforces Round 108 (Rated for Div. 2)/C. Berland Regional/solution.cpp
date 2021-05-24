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

const int Mxn = 2e5 + 5;
int u[Mxn], s[Mxn];
vi t[Mxn];
ll k[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        fori(i,0,n) t[i].clear();
        fore(i,1,n) k[i] = 0;
        fori(i,0,n) cin >> u[i];
        fori(i,0,n) {
            cin >> s[i];
            t[u[i]-1].eb(s[i]);
        }
        fori(i,0,n) if(sz(t[i])) sort(all(t[i]), greater<int>());
        fori(c,0,n) {
            if(sz(t[c])) {
                int m = sz(t[c]);
                ll p[m+1];
                memset(p, 0, sizeof p);
                fori(i,0,m) p[i+1] = p[i]+t[c][i]; 
                fore(i,1,m) {
                    for(int j = 1; j*j <= i; j++) {
                        if(i % j == 0) { 
                            k[j] += p[i]-p[i-j];
                            if(i/j != j) k[i/j] += p[i]-p[i-(i/j)];
                        }
                    }
                }
            }
        }
        fore(i,1,n) cout << k[i] << ' ';
        cout << endl;
    }
    return 0; 
}