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

const int Mxn = 1e5 + 5;
bitset<Mxn> b[10][10];
vi mach[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int m = 0;
    bitset<Mxn> def(string(Mxn, '1'));
    fori(q,0,n) {
        char c;
        cin >> c;
        vi v(9);
        if(c == 'C' || c == 'J') {
            int r; cin >> r;
            fori(i,0,r) {
                int t; cin >> t;
                t--;
                v[t]++;
            }
        }
        if(c == 'C') {
            fori(i,0,8) {
                fore(j,1,v[i])
                    b[i][j] |= 1 << m;
            }
            mach[m++] = v;
        }
        else if(c == 'D') {
            int id; cin >> id;
            id--;
            v = mach[id];
            fori(i,0,8) {
                fore(j,1,v[i])
                    b[i][j] ^= 1 << id;
            }
        } else {
            bitset<Mxn> ans = def;
            fori(i,0,8) {
                fore(j,1,v[i]) ans &= b[i][j];
            }
            cout << ans.count() << endl;
        }
    }
    return 0; 
}