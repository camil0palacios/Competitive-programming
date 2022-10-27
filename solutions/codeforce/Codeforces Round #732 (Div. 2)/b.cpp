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

const int Mxn =  1e5 + 5;
string a[Mxn], b[Mxn];
int p[Mxn][26];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n-1) cin >> b[i];
        fori(i,0,m) fori(j,0,26) p[i][j] = 0;
        fori(i,0,n) fori(j,0,m) p[j][a[i][j] - 'a']++;
        fori(i,0,n-1) fori(j,0,m) p[j][b[i][j] - 'a']++;
        set<int> s;
        fori(i,0,n) s.insert(i);
        fori(j,0,m) {
            set<int> ns;
            for(auto & i : s) {
                if(p[j][a[i][j] -'a'] & 1) ns.insert(i); 
            }
            s = ns;
            if(sz(s) == 1) break;
        }
        cout << a[*s.begin()] << endl;
    }
    return 0; 
}