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

const int Mxn = 110;
int p[Mxn], k[Mxn];
vi g[Mxn];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) p[b] = a;
} 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) p[i] = i;
    fori(i,0,n) {
        cin >> k[i];
        fori(j,0,k[i]) {
            int a; cin >> a;
            for(auto & v : g[a]) join(i, v); 
            g[a].eb(i);
        }
    }
    set<int> s;
    int z = 0;
    fori(i,0,n) {
        if(k[i]) s.insert(find(i));
        else z++;
    }
    int ans = z;
    if(sz(s)) ans += sz(s)-1;
    cout << ans << endl;
    return 0; 
}